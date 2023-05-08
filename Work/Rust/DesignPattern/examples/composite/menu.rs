use crate::{MenuComponentEnum, Menu, MenuItem, MenuComponent};

/// Construct the menu with all its contents
pub fn make_all_menus() -> MenuComponentEnum {
    let mut pancake_house_menu: MenuComponentEnum =
        Menu::new("Pancake House menu", "Breakfast").into();
    let mut dinner_menu: MenuComponentEnum = Menu::new("Dinner Menu", "Lunch").into();
    let mut cafe_menu: MenuComponentEnum = Menu::new("Cafe Menu", "Dinner").into();
    let mut dessert_menu: MenuComponentEnum =
        Menu::new("Dessert Menu", "Dessert of course!").into();

    // *************

    pancake_house_menu.add(
        MenuItem::new(
            "K&B Pancake Breakfast",
            "Pancakes with scrambled eggs, and toast",
            true,
            2.99,
        )
        .into(),
    );

    pancake_house_menu.add(
        MenuItem::new(
            "Regular Pancake Breakfast",
            "Pancakes with fried eggs, sausage",
            false,
            2.99,
        )
        .into(),
    );

    pancake_house_menu.add(
        MenuItem::new(
            "Regular Pancake Breakfast",
            "Pancakes with fried eggs, sausage",
            false,
            2.99,
        )
        .into(),
    );

    pancake_house_menu.add(
        MenuItem::new(
            "Blueberry Pancakes",
            "Pancakes made with fresh blueberries",
            true,
            3.49,
        )
        .into(),
    );

    pancake_house_menu.add(
        MenuItem::new(
            "Waffles",
            "Waffles with your choice of blueberries or strawberries",
            true,
            3.59,
        )
        .into(),
    );

    // *******

    dinner_menu.add(
        MenuItem::new(
            "Vegetarian BLT",
            "Fakin Bacon with lettuce and tomato on whole wheat",
            true,
            2.99,
        )
        .into(),
    );
    dinner_menu.add(
        MenuItem::new(
            "BLT",
            "Bacon with lettuce and tomato on whole wheat",
            false,
            2.99,
        )
        .into(),
    );
    dinner_menu.add(
        MenuItem::new(
            "Soup of the day",
            "Soup of the day, with a side of potato salad",
            false,
            3.29,
        )
        .into(),
    );
    dinner_menu.add(
        MenuItem::new(
            "Hotdog",
            "A hot dog, with saurkraut, relish, onions, topped with cheese",
            false,
            3.05,
        )
        .into(),
    );
    //
    dessert_menu.add(
        MenuItem::new(
            "Apple pie",
            "Apple pie with a flakey crust, topped with vanilla ice cream",
            true,
            1.59,
        )
        .into(),
    );
    dessert_menu.add(
        MenuItem::new(
            "Banana pie",
            "Banana pie with a flakey crust, topped with vanilla ice cream",
            true,
            2.59,
        )
        .into(),
    );
    dessert_menu.add(
        MenuItem::new(
            "Pineapple pie",
            "Pineapple pie with a flakey crust, topped with vanilla ice cream",
            true,
            3.59,
        )
        .into(),
    );
    //
    dinner_menu.add(dessert_menu);

    // *******

    cafe_menu.add(
        MenuItem::new(
            "Vegie Burger and Fries",
            "Veggie burger on a whole wheat bun, lettuce, tomato, and fries",
            true,
            3.99,
        )
        .into(),
    );
    cafe_menu.add(
        MenuItem::new(
            "Soup of the day",
            "A cup of soup of the day, with a side salad",
            false,
            3.69,
        )
        .into(),
    );
    cafe_menu.add(
        MenuItem::new(
            "Burrito",
            "A large burrito, with whole pinto beans, salsa and guacamole",
            true,
            4.29,
        )
        .into(),
    );

    // *******

    let mut all_menus: MenuComponentEnum = Menu::new("All Menus", "All menus combined").into();
    all_menus.add(pancake_house_menu);
    all_menus.add(dinner_menu);
    all_menus.add(cafe_menu);

    all_menus
}
