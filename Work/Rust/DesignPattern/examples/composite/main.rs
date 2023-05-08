mod menu;

use enum_delegate;
use menu::make_all_menus;

#[enum_delegate::register]
trait MenuComponent {
    fn get_name(&self) -> String;
    fn get_description(&self) -> String;
    fn get_price(&self) -> f64;
    fn is_vegetarian(&self) -> bool;
    fn print(&self);
    fn add(&mut self, menu: MenuComponentEnum);
    // ...
}

#[enum_delegate::implement(MenuComponent)]
pub enum MenuComponentEnum {
    Menu(Menu),
    MenuItem(MenuItem),
}

// ***************************************************

pub struct MenuItem {
    name: String,
    description: String,
    vegetarian: bool,
    price: f64,
}

impl MenuItem {
    fn new(name: String, description: String, vegetarian: bool, price: f64) -> Self {
        Self {
            name,
            description,
            vegetarian,
            price,
        }
    }
}

impl MenuComponent for MenuItem {
    fn get_name(&self) -> String {
        self.name.clone()
    }

    fn get_description(&self) -> String {
        self.description.clone()
    }

    fn get_price(&self) -> f64 {
        self.price
    }

    fn is_vegetarian(&self) -> bool {
        self.vegetarian
    }

    fn print(&self) {
        print!("    {}, ", self.get_name());
        if self.is_vegetarian() {
            print!("(V), ")
        };
        print!("{}", self.get_price());
        print!("{}", self.get_description());
        println!("");
    }

    fn add(&mut self, _menu: MenuComponentEnum) {
        todo!()
    }
}

// ***************************************************

pub struct Menu {
    name: String,
    description: String,
    components: Vec<MenuComponentEnum>,
}

impl Menu {
    fn new(name: String, description: String) -> Self {
        Self {
            name,
            description,
            components: Vec::new(),
        }
    }
}

impl MenuComponent for Menu {
    fn get_name(&self) -> String {
        self.name.clone()
    }

    fn get_description(&self) -> String {
        self.description.clone()
    }

    fn get_price(&self) -> f64 {
        todo!()
    }

    fn is_vegetarian(&self) -> bool {
        todo!()
    }

    fn print(&self) {
        println!();
        println!("{}, {}", self.get_name(), self.get_description());
        println!("-----------------------------");
        for each in &self.components {
            each.print()
        }
    }

    fn add(&mut self, menu_component: MenuComponentEnum) {
        self.components.push(menu_component)
    }
}

// ***************************************************

struct Alice {
    all_menus: MenuComponentEnum,
}

impl Alice {
    fn new(all_menus: MenuComponentEnum) -> Self {
        Self { all_menus }
    }

    fn print_menu(&self) {
        self.all_menus.print()
    }
}

// ***************************************************

fn main() {
    let all_menus = make_all_menus();

    let alice = Alice::new(all_menus);
    alice.print_menu();
}
