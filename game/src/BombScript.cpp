/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** BombScript
*/

#include "Components/RigidBody.hpp"
#include "BombScript.hpp"
#include "FireScript.hpp"
#include "Components.hpp"
#include "Components/PowerUp.hpp"
#include "raylib-cpp/Rectangle.hpp"
#include <vector>

BombScript::BombScript(const std::string &player, int rangeUp) : playerName(player), _rangeUp(rangeUp) {}

void BombScript::createPowerUp(Vec3 position)
{
    int powerUpGenerator = std::rand()/((RAND_MAX + 1u)/3);
    std::string powerUpPath = "assets/bonus/";
    std::string powerUpTag;

    switch (powerUpGenerator)
    {
    case 0:
        powerUpPath += "bomb.gltf";
        powerUpTag = "bomb_power_up";
        break;
    case 1:
        powerUpPath += "fire.gltf";
        powerUpTag = "fire_power_up";
        break;
    case 2:
        powerUpPath += "speed.gltf";
        powerUpTag = "speed_power_up";
        break;
    default:
        break;
    }
    get_world().new_entity("", powerUpTag, true)
        .add<fox::Transform>(position, Vec3(0.75, 0.75, 0.75))
        .add<BoxCollider>(get_scene(), Vec3(0.75, 0.75, 0.75))
        .add<fox::RigidBody>(get_scene())
        .add<ray::Model>(powerUpPath)
        .get<fox::RigidBody>()->get_rb()->setType(reactphysics3d::BodyType::STATIC);
}

void BombScript::on_create()
{
    add_component<ray::Model>("assets/bomb/bomb.gltf");
    add_component<fox::Transform>();
    add_component<Animator>();
     get_component<Animator>()->add_anim("Normal")
         .loop(true)
         .signal(2, [this]{get_component<Animator>()->switch_to("Explode");})
      .add<Vec3>()
         .apply(get_component<fox::Transform>()->scale)
         .then(0, Vec3(1, 1, 1))
         .then(1, Vec3(1.3, 1.3, 1.3))
         .then(2, Vec3(1, 1, 1));

     get_component<Animator>()->add_anim("Explode")
         .signal(2, [this]{

    std::vector<fox::Entity> entities;
    std::vector<fox::Entity> toRemove;
    fox::Entity e;

    get_world().get_entity(playerName, e);
    int bombRangeUp = e.get<PowerUp>()->getBombRangeUp();

    entities = get_world().get_entities_with<fox::Health, fox::Transform>();
    bool one = false;
    bool two = false;
    bool three = false;
    bool four = false;
    Vec3 bombPosition = get_component<fox::Transform>()->position;
    std::vector<fox::Entity> indestructible;
    get_world().get_entities_with_tag("indestructible_block", indestructible);
    if (!entities.empty())
    {

        for (std::vector<fox::Entity>::iterator it = entities.begin(); it != entities.end(); it++) {
            if (!it->is_enable())
                continue;
            Vec3 wallPosition = it->get<fox::Transform>()->position;

            if ((wallPosition.z > bombPosition.z - 1.5 &&
                wallPosition.z < bombPosition.z) &&
                (wallPosition.x <= bombPosition.x + 0.5 &&
                wallPosition.x >= bombPosition.x - 0.5)) {
                one = true;
                toRemove.push_back(*it);
                continue;
            }

            for (std::vector<fox::Entity>::iterator it2 = indestructible.begin(); it2 != indestructible.end(); it2++) {
                Vec3 position = it2->get<fox::Transform>()->position;
                if ((position.z > bombPosition.z - 1.5 &&
                    position.z < bombPosition.z) &&
                    (position.x <= bombPosition.x + 0.5 &&
                    position.x >= bombPosition.x - 0.5)) {
                    one = true;
                    break;
                }
            }

            if (one == false) {
                for (int x = 0; x <= bombRangeUp && one == false; x++) {
                    if ((wallPosition.z > bombPosition.z - 2.5 - x &&
                        wallPosition.z < bombPosition.z - 1.5) &&
                        (wallPosition.x <= bombPosition.x + 0.5 &&
                        wallPosition.x >= bombPosition.x - 0.5)) {
                        one = true;
                        toRemove.push_back(*it);
                        continue;
                    }
                }
            }

            if (wallPosition.z < bombPosition.z + 1.5 &&
                wallPosition.z > bombPosition.z &&
                wallPosition.x >= bombPosition.x - 0.5 &&
                wallPosition.x <= bombPosition.x + 0.5) {
                toRemove.push_back(*it);
                two = true;
                continue;
            }

            for (std::vector<fox::Entity>::iterator it2 = indestructible.begin(); it2 != indestructible.end(); it2++) {
                Vec3 position = it2->get<fox::Transform>()->position;
                if (position.z < bombPosition.z + 1.5 &&
                position.z > bombPosition.z &&
                position.x >= bombPosition.x - 0.5 &&
                position.x <= bombPosition.x + 0.5) {
                    two = true;
                    break;
                }
            }

            if (two == false) {
                for (int x = 0; x <= bombRangeUp && two == false; x++) {
                    if ((wallPosition.z < bombPosition.z + 2.5 + x &&
                        wallPosition.z > bombPosition.z + 1.5 &&
                        wallPosition.x >= bombPosition.x - 0.5 &&
                        wallPosition.x <= bombPosition.x + 0.5)) {
                        two = true;
                        toRemove.push_back(*it);
                        continue;
                    }
                }
            }

            if (wallPosition.x > bombPosition.x - 1.5 &&
                wallPosition.x < bombPosition.x &&
                wallPosition.z <= bombPosition.z + 0.5 &&
                wallPosition.z >= bombPosition.z - 0.5) {
                toRemove.push_back(*it);
                three = true;
                continue;
            }

            for (std::vector<fox::Entity>::iterator it2 = indestructible.begin(); it2 != indestructible.end(); it2++) {
                Vec3 position = it2->get<fox::Transform>()->position;
                if (position.x > bombPosition.x - 1.5 &&
                position.x < bombPosition.x &&
                position.z <= bombPosition.z + 0.5 &&
                position.z >= bombPosition.z - 0.5) {
                    three = true;
                    break;
                }
            }

            if (three == false) {
                for (int x = 0; x <= bombRangeUp && three == false; x++) {
                    if (wallPosition.x > bombPosition.x - 2.5 - x &&
                        wallPosition.x < bombPosition.x - 1.5 &&
                        wallPosition.z <= bombPosition.z + 0.5 &&
                        wallPosition.z >= bombPosition.z - 0.5) {
                        three = true;
                        toRemove.push_back(*it);
                        continue;
                    }
                }
            }

            if (wallPosition.x < bombPosition.x + 1.5 &&
                wallPosition.x > bombPosition.x &&
                wallPosition.z >= bombPosition.z - 0.5 &&
                wallPosition.z <= bombPosition.z + 0.5) {
                toRemove.push_back(*it);
                four = true;
                continue;
            }

            for (std::vector<fox::Entity>::iterator it2 = indestructible.begin(); it2 != indestructible.end(); it2++) {
                Vec3 position = it2->get<fox::Transform>()->position;
                if (position.x < bombPosition.x + 1.5 &&
                position.x > bombPosition.x &&
                position.z >= bombPosition.z - 0.5 &&
                position.z <= bombPosition.z + 0.5) {
                    four = true;
                    break;
                }
            }

            if (four == false) {
                for (int x = 0; x <= bombRangeUp && four == false; x++) {
                    if (wallPosition.x < bombPosition.x + 2.5 + x &&
                        wallPosition.x > bombPosition.x + 1.5 &&
                        wallPosition.z >= bombPosition.z - 0.5 &&
                        wallPosition.z <= bombPosition.z + 0.5) {
                        four = true;
                        toRemove.push_back(*it);
                        continue;
                    }
                }
            }
        }
    }

    get_world().get_entity(playerName, e);
    e.get<PowerUp>()->decreaseNumberOfBomb();
    for (std::vector<fox::Entity>::iterator it = toRemove.begin(); it != toRemove.end(); it++) {
        auto optionTag = it->get<fox::EntityTag>();
        auto optionName = it->get<fox::EntityName>();
        if (optionTag && optionTag.value().get() == "players")
            if (optionName && optionName.value().get() != playerName)
                get_app().get_player_manager().incrementScore(playerName, 100);
        it->get<fox::Health>()->take_damage(1);
        get_world().new_entity()
            .add<NativeScript>()
            .get<NativeScript>()->bind<FireScript>(it->get<fox::Transform>()->position);
        if (std::rand()/((RAND_MAX + 1u)/4) == 1)
            createPowerUp(it->get<fox::Transform>()->position);
    }

    bool top = true;
    bool bottom = true;
    bool left = true;
    bool right = true;
    std::vector<fox::Entity> wall;
    get_world().get_entities_with_tag("wall", wall);
        std::vector<fox::Entity> destructible;
    get_world().get_entities_with_tag("destructible_block", destructible);

    //top first case
        for (std::vector<fox::Entity>::iterator it = wall.begin(); it != wall.end(); it++) {
            Vec3 wallPosition = it->get<fox::Transform>()->position;
            if (wallPosition.z > bombPosition.z - 1.5 &&
                wallPosition.z < bombPosition.z &&
                wallPosition.x <= bombPosition.x + 0.5 &&
                wallPosition.x >= bombPosition.x - 0.5) {
                    top = false;
                    break;
                }
        }
        if (top) {
            for (std::vector<fox::Entity>::iterator it = indestructible.begin(); it != indestructible.end(); it++) {
            Vec3 indestructiblePosition = it->get<fox::Transform>()->position;
            if (indestructiblePosition.z > bombPosition.z - 1.5 &&
                indestructiblePosition.z < bombPosition.z &&
                indestructiblePosition.x <= bombPosition.x + 0.5 &&
                indestructiblePosition.x >= bombPosition.x - 0.5) {
                    top = false;
                    break;
                }
            }
        }

        if (top) {
            get_world().new_entity()
                .add<NativeScript>()
                .get<NativeScript>()->bind<FireScript>(Vec3(bombPosition.x, 1, (bombPosition.z - 1)));
        }

    for (std::vector<fox::Entity>::iterator it = destructible.begin(); it != destructible.end(); it++) {
        Vec3 destructiblePosition = it->get<fox::Transform>()->position;
        if (destructiblePosition.z > bombPosition.z - 1.5 &&
            destructiblePosition.z < bombPosition.z &&
            destructiblePosition.x <= bombPosition.x + 0.5 &&
            destructiblePosition.x >= bombPosition.x - 0.5) {
            top = false;
            break;
        }
    }
    //top second case

    for (int x = 0; x <= bombRangeUp && top == true; x++) {
        if (top) {
            for (std::vector<fox::Entity>::iterator it = wall.begin(); it != wall.end(); it++) {
                Vec3 wallPosition = it->get<fox::Transform>()->position;
                if (wallPosition.z > bombPosition.z - 2.5 - x &&
                    wallPosition.z < bombPosition.z &&
                    wallPosition.x <= bombPosition.x + 0.5 &&
                    wallPosition.x >= bombPosition.x - 0.5) {
                        top = false;
                        break;
                    }
            }
        }

        if (top) {
            for (std::vector<fox::Entity>::iterator it = indestructible.begin(); it != indestructible.end(); it++) {
            Vec3 indestructiblePosition = it->get<fox::Transform>()->position;
            if (indestructiblePosition.z > bombPosition.z - 2.5 - x &&
                indestructiblePosition.z < bombPosition.z &&
                indestructiblePosition.x <= bombPosition.x + 0.5 &&
                indestructiblePosition.x >= bombPosition.x - 0.5) {
                    top = false;
                    break;
                }
            }
        }

        for (std::vector<fox::Entity>::iterator it = destructible.begin(); it != destructible.end(); it++) {
        Vec3 destructiblePosition = it->get<fox::Transform>()->position;
        if (destructiblePosition.z > bombPosition.z - 2.5 - x &&
            destructiblePosition.z < bombPosition.z &&
            destructiblePosition.x <= bombPosition.x + 0.5 &&
            destructiblePosition.x >= bombPosition.x - 0.5) {
            top = false;
            break;
        }
    }

        if (top) {
            get_world().new_entity()
                .add<NativeScript>()
                .get<NativeScript>()->bind<FireScript>(Vec3(bombPosition.x, 1, (bombPosition.z - 2 - x)));
        }
    }

    // bottom first case
    for (std::vector<fox::Entity>::iterator it = wall.begin(); it != wall.end(); it++) {
        Vec3 wallPosition = it->get<fox::Transform>()->position;
        if (wallPosition.z < bombPosition.z + 1.5 &&
            wallPosition.z > bombPosition.z &&
            wallPosition.x >= bombPosition.x - 0.5 &&
            wallPosition.x <= bombPosition.x + 0.5) {
                bottom = false;
                break;
            }
    }
    if (bottom) {
        for (std::vector<fox::Entity>::iterator it = indestructible.begin(); it != indestructible.end(); it++) {
        Vec3 indestructiblePosition = it->get<fox::Transform>()->position;
        if (indestructiblePosition.z < bombPosition.z + 1.5 &&
            indestructiblePosition.z > bombPosition.z &&
            indestructiblePosition.x >= bombPosition.x - 0.5 &&
            indestructiblePosition.x <= bombPosition.x + 0.5) {
                bottom = false;
                break;
            }
        }
    }
    if (bottom) {
        get_world().new_entity()
            .add<NativeScript>()
            .get<NativeScript>()->bind<FireScript>(Vec3(bombPosition.x, 1, (bombPosition.z + 1)));
    }

    for (std::vector<fox::Entity>::iterator it = destructible.begin(); it != destructible.end(); it++) {
    Vec3 destructiblePosition = it->get<fox::Transform>()->position;
    if (destructiblePosition.z < bombPosition.z + 1.5 &&
        destructiblePosition.z > bombPosition.z &&
        destructiblePosition.x >= bombPosition.x - 0.5 &&
        destructiblePosition.x <= bombPosition.x + 0.5) {
            bottom = false;
            break;
        }
    }
    // bottom second case

    for (int x = 0; x <= bombRangeUp && bottom == true; x++) {
        for (std::vector<fox::Entity>::iterator it = wall.begin(); it != wall.end(); it++) {
            Vec3 wallPosition = it->get<fox::Transform>()->position;
            if (wallPosition.z < bombPosition.z + 2.5 + x &&
                wallPosition.z > bombPosition.z &&
                wallPosition.x >= bombPosition.x - 0.5 &&
                wallPosition.x <= bombPosition.x + 0.5) {
                    bottom = false;
                    break;
                }
        }
        if (bottom) {
            for (std::vector<fox::Entity>::iterator it = indestructible.begin(); it != indestructible.end(); it++) {
            Vec3 indestructiblePosition = it->get<fox::Transform>()->position;
            if (indestructiblePosition.z < bombPosition.z + 2.5 + x &&
                indestructiblePosition.z > bombPosition.z &&
                indestructiblePosition.x >= bombPosition.x - 0.5 &&
                indestructiblePosition.x <= bombPosition.x + 0.5) {
                    bottom = false;
                    break;
                }
            }
        }

        for (std::vector<fox::Entity>::iterator it = destructible.begin(); it != destructible.end(); it++) {
            Vec3 destructiblePosition = it->get<fox::Transform>()->position;
            if (destructiblePosition.z < bombPosition.z + 1.5 + x &&
                destructiblePosition.z > bombPosition.z &&
                destructiblePosition.x >= bombPosition.x - 0.5 &&
                destructiblePosition.x <= bombPosition.x + 0.5) {
                bottom = false;
                break;
                }
        }

        if (bottom) {
            get_world().new_entity()
                .add<NativeScript>()
                .get<NativeScript>()->bind<FireScript>(Vec3(bombPosition.x, 1, (bombPosition.z + 2 + x)));
        }
    }

    // left first case

    for (std::vector<fox::Entity>::iterator it = wall.begin(); it != wall.end(); it++) {
        Vec3 wallPosition = it->get<fox::Transform>()->position;
        if (wallPosition.x > bombPosition.x - 1.5 &&
            wallPosition.x < bombPosition.x &&
            wallPosition.z <= bombPosition.z + 0.5 &&
            wallPosition.z >= bombPosition.z - 0.5) {
                left = false;
                break;
            }
    }
    if (left) {
        for (std::vector<fox::Entity>::iterator it = indestructible.begin(); it != indestructible.end(); it++) {
        Vec3 indestructiblePosition = it->get<fox::Transform>()->position;
        if (indestructiblePosition.x > bombPosition.x - 1.5 &&
            indestructiblePosition.x < bombPosition.x &&
            indestructiblePosition.z <= bombPosition.z + 0.5 &&
            indestructiblePosition.z >= bombPosition.z - 0.5) {
                left = false;
                break;
            }
        }
    }
    if (left) {
        get_world().new_entity()
            .add<NativeScript>()
            .get<NativeScript>()->bind<FireScript>(Vec3(bombPosition.x - 1, 1, (bombPosition.z)));
    }

    for (std::vector<fox::Entity>::iterator it = destructible.begin(); it != destructible.end(); it++) {
    Vec3 destructiblePosition = it->get<fox::Transform>()->position;
    if (destructiblePosition.x > bombPosition.x - 1.5 &&
            destructiblePosition.x < bombPosition.x &&
            destructiblePosition.z <= bombPosition.z + 0.5 &&
            destructiblePosition.z >= bombPosition.z - 0.5) {
            left = false;
            break;
        }
    }
    // left second case

    for (int x = 0; x <= bombRangeUp && left == true; x++) {
        for (std::vector<fox::Entity>::iterator it = wall.begin(); it != wall.end(); it++) {
            Vec3 wallPosition = it->get<fox::Transform>()->position;
            if (wallPosition.x > bombPosition.x - 2.5 - x &&
                wallPosition.x < bombPosition.x - 1.5 &&
                wallPosition.z <= bombPosition.z + 0.5 &&
                wallPosition.z >= bombPosition.z - 0.5) {
                    left = false;
                    break;
                }
        }
        if (left) {
            for (std::vector<fox::Entity>::iterator it = indestructible.begin(); it != indestructible.end(); it++) {
            Vec3 indestructiblePosition = it->get<fox::Transform>()->position;
            if (indestructiblePosition.x > bombPosition.x - 2.5 - x &&
                indestructiblePosition.x < bombPosition.x - 1.5 &&
                indestructiblePosition.z <= bombPosition.z + 0.5 &&
                indestructiblePosition.z >= bombPosition.z - 0.5) {
                    left = false;
                    break;
                }
            }
        }

        for (std::vector<fox::Entity>::iterator it = destructible.begin(); it != destructible.end(); it++) {
        Vec3 destructiblePosition = it->get<fox::Transform>()->position;
        if (destructiblePosition.x > bombPosition.x - 2.5 - x &&
                destructiblePosition.x < bombPosition.x - 1.5 &&
                destructiblePosition.z <= bombPosition.z + 0.5 &&
                destructiblePosition.z >= bombPosition.z - 0.5) {
                left = false;
                break;
            }
        }

        if (left) {
            get_world().new_entity()
                .add<NativeScript>()
                .get<NativeScript>()->bind<FireScript>(Vec3(bombPosition.x - 2 - x, 1, (bombPosition.z)));
        }
    }

    // right first case

    for (std::vector<fox::Entity>::iterator it = wall.begin(); it != wall.end(); it++) {
        Vec3 wallPosition = it->get<fox::Transform>()->position;
        if (wallPosition.x < bombPosition.x + 1.5 &&
            wallPosition.x > bombPosition.x &&
            wallPosition.z >= bombPosition.z - 0.5 &&
            wallPosition.z <= bombPosition.z + 0.5) {
                right = false;
                break;
            }
    }
    if (right) {
        for (std::vector<fox::Entity>::iterator it = indestructible.begin(); it != indestructible.end(); it++) {
        Vec3 indestructiblePosition = it->get<fox::Transform>()->position;
        if (indestructiblePosition.x < bombPosition.x + 1.5 &&
            indestructiblePosition.x > bombPosition.x &&
            indestructiblePosition.z >= bombPosition.z - 0.5 &&
            indestructiblePosition.z <= bombPosition.z + 0.5) {
                right = false;
                break;
            }
        }
    }
    if (right) {
        get_world().new_entity()
            .add<NativeScript>()
            .get<NativeScript>()->bind<FireScript>(Vec3(bombPosition.x + 1, 1, (bombPosition.z)));
    }

    for (std::vector<fox::Entity>::iterator it = destructible.begin(); it != destructible.end(); it++) {
    Vec3 destructiblePosition = it->get<fox::Transform>()->position;
    if (destructiblePosition.x < bombPosition.x + 1.5 &&
        destructiblePosition.x > bombPosition.x &&
        destructiblePosition.z >= bombPosition.z - 0.5 &&
        destructiblePosition.z <= bombPosition.z + 0.5) {
            right = false;
            break;
        }
    }
    // right second case

    for (int x = 0; x <= bombRangeUp && right == true; x++) {
        for (std::vector<fox::Entity>::iterator it = wall.begin(); it != wall.end(); it++) {
            Vec3 wallPosition = it->get<fox::Transform>()->position;
            if (wallPosition.x < bombPosition.x + 2.5 + x &&
                wallPosition.x > bombPosition.x &&
                wallPosition.z >= bombPosition.z - 0.5 &&
                wallPosition.z <= bombPosition.z + 0.5) {
                    right = false;
                    break;
                }
        }
        if (right) {
            for (std::vector<fox::Entity>::iterator it = indestructible.begin(); it != indestructible.end(); it++) {
            Vec3 indestructiblePosition = it->get<fox::Transform>()->position;
            if (indestructiblePosition.x < bombPosition.x + 2.5 + x &&
                indestructiblePosition.x > bombPosition.x &&
                indestructiblePosition.z >= bombPosition.z - 0.5 &&
                indestructiblePosition.z <= bombPosition.z + 0.5) {
                    right = false;
                    break;
                }
            }
        }
        for (std::vector<fox::Entity>::iterator it = destructible.begin(); it != destructible.end(); it++) {
        Vec3 destructiblePosition = it->get<fox::Transform>()->position;
        if (destructiblePosition.x < bombPosition.x + 2.5 + x &&
            destructiblePosition.x > bombPosition.x &&
            destructiblePosition.z >= bombPosition.z - 0.5 &&
            destructiblePosition.z <= bombPosition.z + 0.5) {
                right = false;
                break;
            }
        }
        if (right) {
            get_world().new_entity()
                .add<NativeScript>()
                .get<NativeScript>()->bind<FireScript>(Vec3(bombPosition.x + 2 + x, 1, (bombPosition.z)));
        }
    }

    get_world().new_entity()
        .add<NativeScript>()
        .get<NativeScript>()->bind<FireScript>(Vec3(bombPosition.x, 1, (bombPosition.z)));
    get_app().PlaySound("GroupEffect", "assets/sounds/bomb_explosion.ogg", 1, 1);
    destroy();
    })
     .add<Vec3>()
     .apply(get_component<fox::Transform>()->scale)
     .then(0, Vec3(1, 1, 1))
     .then(2, Vec3(1.5, 1.5, 1.5));
}

void BombScript::on_update() {}

void BombScript::on_destroy() {}
