# so_long

**so_long** is a small 2D game developed as part of the 42 school curriculum. It focuses on basic game logic, graphics handling, and keyboard events using the MiniLibX graphical library.

## 🎮 Game Objective

You control Vegeta, who must collect all the Dragon Balls (`C`) scattered throughout the map and reach the pod (`E`) to escape. The game ends successfully once all collectibles are gathered and the player reaches the exit.

---

## 🧱 Map Format

The map is loaded from a `.ber` file and is composed of the following elements:

- `1` → Wall (impassable)
- `0` → Empty space
- `C` → Collectible (Dragon Ball)
- `E` → Exit (Saiyan pod)
- `P` → Player's starting position (Vegeta)

---

## 🕹️ Controls

| Key  | Action             |
|------|--------------------|
| W    | Move up            |
| A    | Move left          |
| S    | Move down          |
| D    | Move right         |
| ESC  | Quit the game      |

The number of player movements is printed in the terminal.

---

## 🖼️ Extra Features

- Flying animation using alternating sprites per direction
- Fullscreen intro image
- Movement counter
- Transparent and custom pixel art sprites
- Visual theme inspired by Dragon Ball universe 🐉

---

## ⚙️ Compilation and Execution

```bash
make
./so_long maps/example.ber
