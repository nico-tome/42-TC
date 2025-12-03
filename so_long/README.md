# 🐬 So Long

## 👾 Goal

The goal of the project is to learn to use a graphic librairy to display a map saved in a *.ber file.
The goal of the game is to collect all the collectibles and then to exit the map by reaching the exit tile.

## 🕹 Controls

- Esc: exit the game

(Manda)
- W: up
- S: down
- A: left
- D: right

(bonus)
- Q: attack the enemy in the tile in front of you
- Enter: enable/disable edit mode
- Space: place tile in edit mode
- X: save map in file in edit mode
- H: hide/show help text
- 0: select empty tile
- 1: select wall tile
- 2: select coin tile
- 3: select spawn tile
- 4: select exit tile
- 5: select spike tile
- 6: select vertical enemy tile
- 7: select horizontal enemy tile

---

## The project himself

To create this priject I use the [MacroLibX](https://github.com/seekrs/MacroLibX.git), the 42 Angoulem version of the MLX.
The logic of my code is simple:

I start by parsing the map given in argument, check if it's a .ber file, check if I can open it. Then i use a [flood fill algorithme](https://en.wikipedia.org/wiki/Flood_fill) to check if I can reach every collectiles and the exit tile. I also check if there is only one spawn and one exit, and also if the map is rectangular and i it's surrounded by walls.

After that I check that all my textures are in the correct folder and with the open permission. Then, I setup the mlx window by following the [doc tutorial](https://macrolibx.kbz8.me/guides/initialization/).
