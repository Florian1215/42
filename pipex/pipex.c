/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:48:29 by fguirama          #+#    #+#             */
/*   Updated: 2022/11/30 14:40:33 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/*
perror		gestion erreur
strerror	gestion erreur

access		verifier si le path d'un fichier existe

dup			duplique un object descriptor
dup2		**

execve		transforme l'appelle du process dans un new process
exit		quit pgm
fork		thread pgm
pipe		pipe read - end
unlink		suprime le nom du lien par path
wait
waitpid
*/

int	main(int ac, char **av)
{
	int		id;
	char	*tab[] = {"ls", "-a", NULL};

	printf("%d\n", access("/bin/ls", X_OK));
	id = fork();

	if (id)
		execv("/bin/ls", tab);
	else
		wait(&id);
	printf("salut comment ca va ");
}
