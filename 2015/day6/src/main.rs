use std::io;
use crate::lights_grid::LightState;

const HEIGHT: u32 = 1000;
const WIDTH: u32 = 1000;

mod lights_grid {
    use LightState::*;
    use PairKind::*;
    use crate::io;
    use crate::WIDTH;

    #[derive(Clone, Copy, Debug, PartialEq)]
    pub enum LightState {
        TurnedOn,
        TurnedOff
    }

    #[derive(Clone, Copy, Debug)]
    enum PairKind {
        OFF,
        ON,
        TOGGLE
    }

    #[derive(Clone, Copy, Debug)]
    pub struct Pair {
        first_corner: Coords,
        second_corner: Coords,
        instruction: PairKind
    }

    impl Pair {
        pub fn new(line: &str) -> Pair {
            let parts: Vec<&str> = line.trim().split(" ").collect();
            let mut first_coords: Coords = Coords { x: 0, y: 0 };
            let mut second_coords: Coords = Coords { x: 0, y: 0 };
            let mut action: PairKind = OFF;

            for i in 0..parts.len() {
                 match parts[i] {
                     "through" => second_coords = Coords::new(parts[i + 1]),
                     "toggle" => {
                         first_coords = Coords::new(parts[i + 1]);
                         action = TOGGLE;
                     },
                     "turn" => match parts[i + 1] {
                         "on" => {
                             action = ON;
                             first_coords = Coords::new(parts[i + 2]);
                         },
                         "off" => {
                             first_coords = Coords::new(parts[i + 2]);
                         },
                         _ => {}
                     }
                     _ => {}
                 }
            }

            Pair {
                first_corner: first_coords,
                second_corner: second_coords,
                instruction: action
            }
        }

        pub fn exec_pair(grid: &Vec<bool>, pair: Pair) {
            match pair.instruction {
                _ => {}
            }
        }
    }

    #[derive(Clone, Copy, Debug)]
    struct Coords {
        x: u32,
        y: u32
    }

    impl Coords {
        pub fn new(line: &str) -> Coords {
            let nums: Vec<&str> = line.split(",").collect();

            Coords {
                x: nums[0].parse().expect("Failed to parse string to uint"),
                y: nums[1].parse().expect("Failed to parse string to uint")
            }
        }

        fn index_to_coords(index: u32) -> Coords {
            Coords { x: index % WIDTH, y: index / WIDTH }
        }

        fn coords_to_index(coords: Coords) -> u32 {
            coords.x + (coords.y * WIDTH)
        }

        fn turn_on(mut grid: Vec<LightState>, coords: Coords) -> io::Result<()> {
            grid[Coords::coords_to_index(coords) as usize] = TurnedOn;
            Ok(())
        }

        fn turn_off(mut grid: Vec<LightState>, coords: Coords) -> io::Result<()> {
            grid[Coords::coords_to_index(coords) as usize] = TurnedOff;
            Ok(())
        }

        fn toggle(mut grid: Vec<LightState>, coords: Coords) -> io::Result<()> {
            grid[Coords::coords_to_index(coords) as usize] = if grid[Coords::coords_to_index(coords) as usize] == TurnedOff { TurnedOn } else { TurnedOff };
            Ok(())
        }
    }
}

use lights_grid::*;
use LightState::*;

fn main() -> io::Result<()> {
    let mut line: String = String::new();
    let mut grid: Vec<LightState>= vec![TurnedOff; (HEIGHT * WIDTH) as usize];
    let mut lit: u32 = 0;


    while io::stdin().read_line(&mut line)? != 0 {
        // do something with line
        let pair = Pair::new(&line);
        println!("{:?}", pair);
        line.clear();
    }

    grid.retain(|&state| state == TurnedOn);
    lit = grid.len() as u32;

    println!("\nNumber of lights lit: {}", lit);

    Ok(())
}
