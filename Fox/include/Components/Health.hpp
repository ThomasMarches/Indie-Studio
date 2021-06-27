/*
** EPITECH PROJECT, 2021
** B-YEP-400-TLS-4-1-indiestudio-thomas.marches
** File description:
** Health
*/

#ifndef HEALTH_HPP_
#define HEALTH_HPP_

namespace fox {

    class Health {
        public:

            /**
             * @brief Constructor
             */
            Health() : health(1) { }

            /**
             * @brief Decrease the health with the damage value pass in parameter
             * @param damage the value to decrease
             */
            void take_damage(int damage)
            {
                health -= damage;
                on_take_damage.notifiy();

                if (health <= 0)
                    died();
            }

            /**
             * @brief Notify that the entity died
             */
            void died()
            {
                on_died.notifiy();
            }

            /**
             * @brief Register a function to be called when it died
             * @param cb the function to register
             */
            void subscribe_died(std::function<void()> cb)
            {
                on_died.subscribe(cb);
            }

            /**
             * @brief Register a function to be called when it take damage
             * @param cb the function to register
             */
            void subscribe_take_damage(std::function<void()> cb)
            {
                on_take_damage.subscribe(cb);
            }

        private:
            int health;
            EventNotifier<void()> on_take_damage;
            EventNotifier<void()> on_died;
    };

}

#endif /* !HEALTH_HPP_ */
