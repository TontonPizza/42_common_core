![final grade](https://github.com/TontonPizza/42_push_swap/blob/master/_archives/86.png)

# push_swap

### Ce projet nous propose de trier des données de manière efficace


On dispose de deux stacks, l'une contient des nombres uniques et doit triée

![Illustration Stack](https://github.com/TontonPizza/push_swap/blob/master/_archives/brochette.gif)

On dispose d'un ensemble de coup et on doit réussir à avoir tout les nombres dans la stack A dans l'ordre croissant.
Le barême prévoit une note maximale pour 700 mouvements pour une stack de taille 100, et 5300 mouvements pour une stack de taille 500.
Soit grosso modo du k N log(N), avec k = 1.5.

#### Angle d'attaque

Première méthode naïve :

Tant que A contient au moins 1 élément :
  mettre le premier élément de A dans B.
  
Tant que B contient au moins 1 élément :
  mettre le plus grand élément de B dans A.
  
  
Cet algorithme naif en N² était néamoins utile pour écrire le programme de vérification.
Les resultats sont de l'ordre de 3500 coups pour 100 éléments, et un timeout pour 500.

Partant sur le même concept (Vider A puis remplir A), J'ai essayé de trouver une fonction d'évaluation pour déterminer le meilleur élément de A à placer dans B.

Le plus petit, le meilleur.
le plus simple à déplacer, le meilleur.

factuellement :

```C
void	solve_ml(t_board board, char **cmd)
{
	if (is_solved(board))
		return ;
	a_to_b(board, cmd);
	b_to_a(board, cmd);
}
```

```C
void 	a_to_b(t_board board, char **cmd)
{
	while (stack_size(board.a) > 0)
	{
		evaluate_positions(board);
		push_best_score(board, cmd);
	}
}

void 	b_to_a(t_board board, char **cmd)
{
	while (stack_size(board.b) > 0)
	{
		push_biggest_to_a(board, cmd);
		if (stack_size(board.a) == 2 && is_stack_asc(board.a) == 0)
			execute_and_append("sa", board, cmd);
	}
}
```

S'ensuit une série de tests très couteux en CPU pour essayer de determiner des coeffs efficaces sur une fonction linéaire, puis de degré deux, puis sur plus de paramètres
(taille de la stack, moyenne des nombres de la stack etc..)
J'ai pu obtenir des moyennes tournant autour de 850 coups pour une stack de taille 100 (note maximale pour < 700).

Je me suis ensuite dirigé vers l'idée qui traîne un peu partout sur internet, jouer avec la valeur médiane.
la fonction d'evaluation devient donc :


le plus simple des éléments plus petit que la médiane le meilleur. Sans compromis.


Cette méthode me donne 710-780 mouvements pour une stack de 100, et environs 7200 pour une stack de 500.

Projet très amusant



