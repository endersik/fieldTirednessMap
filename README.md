# Tiredness Map
This program read inputs from a **file** includes;
- width & height of the field,
- how many times planted in specified year,
- which cells are planted.

## Execution
1. After reading these inputs program generates a 2D array with dynamic memory allocation to represent the field.
2. At first, tiredness of each cell is 0.
3. Program increase tiredness of planted cells by 1 for a year.
4. If a cell doesn't planted for a year its tiredness decrease by 1
5. After reading last years' inputs program draw the map on terminal.
