/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** AI
*/

#include "Components.hpp"
#include "AIScript.hpp"
#include "Components/PowerUp.hpp"
#include "Components/RigidBody.hpp"
#include "BombScript.hpp"

AIScript::AIScript(int x, int y, const std::string &filepath) : _x_bot(x), _y_bot(y), _go_away(5.0), _skinFilepath(filepath)
{
    this->_map.resize(WIDTH_MAP);
    this->_controller = nullptr;
    this->_timer_respawn = 0;

    for (int i = 0; i < WIDTH_MAP; i++)
        this->_map[i].resize(HEIGHT_MAP);
    for (int i = 0; i < WIDTH_MAP; i++)
        for (int j = 0; j < HEIGHT_MAP; j++)
            this->_map[i][j] = 0;
}

void AIScript::on_create()
{
    fox::Entity var;
    add_component<Move>(6);
    _move = &get_component<Move>().value();
    add_component<fox::Score>(0);
    add_component<ray::Model>(_skinFilepath);
    add_component<fox::Health>();
    add_component<BoxCollider>(get_scene());
    add_component<PowerUp>();
    add_component<fox::RigidBody>(get_scene());
    add_component<fox::Transform>(Vec3(_x_bot, 2, _y_bot), Vec3(0.8, 0.8, 0.8));
    get_component<fox::Health>()->subscribe_died([&]
    {
        get_app().PlaySound("GroupEffect", "assets/sounds/death.ogg", 1, 1);
        std::string EntityName = get_component<fox::EntityName>()->get();
        get_component<PowerUp>()->resetPowerUpValues();
        if (get_component<fox::Score>()->getScore() >= 100) {
            get_component<fox::Score>()->decrementScore(100);
            get_app().get_player_manager().incrementScore(EntityName, -100);
        }
        get_component<fox::Transform>()->set_pos(Vec3(_x_bot, 1, _y_bot));
        get_world().enable_entity(get_id(), false);
    });
    get_world().get_entity("map_controller", var);
    _controller = var.get<NativeScript>()->get<MapController>();
    assert(_controller);
}

void AIScript::on_update()
{
    if (get_world().is_entity_enable(get_id()))
        this->set_new_goal();
    else {
        if (_timer_respawn > 4) {
            _timer_respawn = 0;
            get_world().enable_entity(get_id(), true);
        } else {
            _timer_respawn += Time::delta_time / 3;
        }
    }
}

void AIScript::drop_bomb()
{
    fox::Entity e;

    if (get_world().is_entity_enable(get_id())) {
        if (!get_component<PowerUp>()->increaseNumberOfBomb())
            return;
        auto bomb = new_entity()
                .add<NativeScript>()
                .add<fox::Transform>(get_component<fox::Transform>()->position);
        bomb.get<NativeScript>()->bind<BombScript>(get_component<fox::EntityName>()->get(), get_component<PowerUp>()->getBombRangeUp());
        bomb.get<fox::Transform>()->set_pos(get_component<fox::Transform>()->position);
    }
}

void AIScript::move_bot_safe()
{
    for (std::vector<int>::iterator i = this->_path.begin(); i != this->_path.end(); i++) {
        if (*i == 1)
            this->set_x_bot(this->get_x_bot() - 1);
        if (*i == 2)
            this->set_y_bot(this->get_y_bot() - 1);
        if (*i == 3)
            this->set_x_bot(this->get_x_bot() + 1);
        if (*i == 4)
            this->set_y_bot(this->get_y_bot() + 1);
    }
    this->_path.clear();
    this->set_new_goal();
}

int AIScript::find_safe_path(int x, int y)
{
    if (this->get_map()[x][y] == 0)
        return 1;
    if (this->get_map()[x - 1][y] != 2)
        if (find_safe_path(x - 1, y))
            this->_path.push_back(1);
    if (this->get_map()[x][y - 1] != 2)
        if (find_safe_path(x, y))
            this->_path.push_back(2);
    if (this->get_map()[x + 1][y] != 2)
        if (find_safe_path(x + 1, y))
            this->_path.push_back(3);
    if (this->get_map()[x][y + 1] != 2)
        if (find_safe_path(x, y + 1))
            this->_path.push_back(4);
    return 0;
}

void AIScript::set_new_goal()
{
    set_goal();
}

void AIScript::set_goal()
{
    short n = rand() % 4;
    short b = rand() % 7;
    int x = 0;
    int y = 0;
    int cpt = 0;
    int is_break = 0;

    _timer += Time::delta_time;
    if (_timer < _go_away)
        return;
    _move->m_oVelocity.x = 0;
    _move->m_oVelocity.z = 0;
    while (1) {
        if (n == 0) {
            _move->m_oVelocity.x = -_move->m_fSpeed;
            break;
        }
        if (n == 1) {
            _move->m_oVelocity.z = -_move->m_fSpeed;
            break;
        }
        if (n == 2) {
            _move->m_oVelocity.x = _move->m_fSpeed;
            break;
        }
        if (n == 3) {
            _move->m_oVelocity.z = _move->m_fSpeed;
            break;
        }
    }
    _timer = 0.0;
    if (b == 0) {
        this->drop_bomb();
        _move->m_oVelocity.x = -_move->m_oVelocity.x;
        _move->m_oVelocity.z = -_move->m_oVelocity.z;
        if (_move->m_oVelocity.x == 0)
            _move->m_oVelocity.x = _move->m_fSpeed;
        if (_move->m_oVelocity.z == 0)
            _move->m_oVelocity.z = _move->m_fSpeed;
        _go_away = 10.0;
    } else
        _go_away = 5.0;
}

std::vector<std::vector<int>> AIScript::get_map()
{
    return this->_controller->get_grid();
}

int AIScript::get_x_bot()
{
    return this->_x_bot;
}

int AIScript::get_y_bot()
{
    return this->_y_bot;
}

void AIScript::set_x_bot(int x)
{
    this->_x_bot = x;
}

void AIScript::set_y_bot(int y)
{
    this->_y_bot = y;
}
