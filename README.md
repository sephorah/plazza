# Plazza

The purpose of this project is to make a simulation of a pizzeria, which is composed of
the reception that accepts new commands, of several kitchens, themselves with several cooks,
themselves cooking several pizzas.

## Getting started

Build the project.
```
make
```

```
USAGE: ./plazza c n t
	c	multiplier for the cooking time of the pizzas
	n	number of cooks per kitchen
	t	time in milliseconds, used by the kitchen stock to replace ingredients
```

Pizza ordering MUST respect the following grammar:
```
S := TYPE SIZE NUMBER [; TYPE SIZE NUMBER ]*
TYPE := [ a .. zA .. Z ]+
SIZE := S | M | L | XL | XXL
NUMBER := x [1..9][0..9]*
```

Example: `regina XXL x2; fantasia M x3; margarita S x1; monza XL x4`

You might press `ENTER` to send a new command.

## Developers

| [<img src="https://github.com/ivsgabi.png?size=85" width=85><br><sub>Johana GABA</sub>](https://github.com/ivsgabi) | [<img src="https://github.com/sephorah.png?size=85" width=85><br><sub>Séphorah ANIAMBOSSOU</sub>](https://github.com/sephorah)
| :---: | :---: |
