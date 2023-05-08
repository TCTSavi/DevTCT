use crate::{Menu, MenuComponent, MenuComponentEnum, MenuItem};

/// Construct the menu with all its contents
pub fn make_all_menus() -> MenuComponentEnum {
    let mut pancake_house_menu: MenuComponentEnum =
        Menu::new("Pancake House menu".to_string(), "Breakfast".to_string()).into();
    let mut dinner_menu: MenuComponentEnum =
        Menu::new("Dinner Menu".to_string(), "Lunch".to_string()).into();
    let mut cafe_menu: MenuComponentEnum =
        Menu::new("Cafe Menu".to_string(), "Dinner".to_string()).into();
    let mut dessert_menu: MenuComponentEnum =
        Menu::new("Dessert Menu".to_string(), "Dessert of course!".to_string()).into();

    // *************

    pancake_house_menu.add(
        MenuItem::new(
            "K&B Pancake Breakfast".to_string(),
            "Pancakes with scrambled eggs, and toast".to_string(),
            true,
            2.99,
        )
        .into(),
    );

    pancake_house_menu.add(
        MenuItem::new(
            "Regular Pancake Breakfast".to_string(),
            "Pancakes with fried eggs, sausage".to_string(),
            false,
            2.99,
        )
        .into(),
    );

    pancake_house_menu.add(
        MenuItem::new(
            "Regular Pancake Breakfast".to_string(),
            "Pancakes with fried eggs, sausage".to_string(),
            false,
            2.99,
        )
        .into(),
    );

    pancake_house_menu.add(
        MenuItem::new(
            "Blueberry Pancakes".to_string(),
            "Pancakes made with fresh blueberries".to_string(),
            true,
            3.49,
        )
        .into(),
    );

    pancake_house_menu.add(
        MenuItem::new(
            "Waffles".to_string(),
            "Waffles with your choice of blueberries or strawberries".to_string(),
            true,
            3.59,
        )
        .into(),
    );

    // *******

    dinner_menu.add(
        MenuItem::new(
            "Vegetarian BLT".to_string(),
            "Fakin Bacon with lettuce and tomato on whole wheat".to_string(),
            true,
            2.99,
        )
        .into(),
    );
    dinner_menu.add(
        MenuItem::new(
            "BLT".to_string(),
            "Bacon with lettuce and tomato on whole wheat".to_string(),
            false,
            2.99,
        )
        .into(),
    );
    dinner_menu.add(
        MenuItem::new(
            "Soup of the day".to_string(),
            "Soup of the day, with a side of potato salad".to_string(),
            false,
            3.29,
        )
        .into(),
    );
    dinner_menu.add(
        MenuItem::new(
            "Hotdog".to_string(),
            "A hot dog, with saurkraut, relish, onions, topped with cheese".to_string(),
            false,
            3.05,
        )
        .into(),
    );
    //
    dessert_menu.add(
        MenuItem::new(
            "Apple pie".to_string(),
            "Apple pie with a flakey crust, topped with vanilla ice cream".to_string(),
            true,
            1.59,
        )
        .into(),
    );
    dessert_menu.add(
        MenuItem::new(
            "Banana pie".to_string(),
            "Banana pie with a flakey crust, topped with vanilla ice cream".to_string(),
            true,
            2.59,
        )
        .into(),
    );
    dessert_menu.add(
        MenuItem::new(
            "Pineapple pie".to_string(),
            "Pineapple pie with a flakey crust, topped with vanilla ice cream".to_string(),
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
            "Vegie Burger and Fries".to_string(),
            "Veggie burger on a whole wheat bun, lettuce, tomato, and fries".to_string(),
            true,
            3.99,
        )
        .into(),
    );
    cafe_menu.add(
        MenuItem::new(
            "Soup of the day".to_string(),
            "A cup of soup of the day, with a side salad".to_string(),
            false,
            3.69,
        )
        .into(),
    );
    cafe_menu.add(
        MenuItem::new(
            "Burrito".to_string(),
            "A large burrito, with whole pinto beans, salsa and guacamole".to_string(),
            true,
            4.29,
        )
        .into(),
    );

    // *******

    let mut all_menus: MenuComponentEnum =
        Menu::new("All Menus".to_string(), "All menus combined".to_string()).into();
    all_menus.add(pancake_house_menu);
    all_menus.add(dinner_menu);
    all_menus.add(cafe_menu);

    all_menus
}
