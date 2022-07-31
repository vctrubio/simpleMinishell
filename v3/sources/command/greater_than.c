#include "../../includes/command.h"

char *_command_token(char **name, t_node_command *command);

char *_command_pre_greater_than(t_node_command *invoker, t_node_command *this)
{
	char *name;

	if (_command_token(&name, this->next))
	{
		printf("Minishell: syntax error near unexpected token `%s'\n", name);
		_command().delete_all();
		return ("");
	}
	(void)invoker;
	_file().create(this->fd, _string().dup(this->next->name), O_TRUNC);
	_command().delete(this->next);
	if (this->next)
		return (this->next->pre_function(invoker, this->next));
	return ("");
}

void _command_greater_than(t_node_command *this)
{
	char *name;

	if (!this->fd[0])
	{
		if (_command_token(&name, this->next))
		{
			printf("Minishell: syntax error near unexpected token `%s'\n", name);
			_command().delete_all();
			return;
		}
		_file().create(this->fd, _string().dup(this->next->name), O_TRUNC);
		_command().delete(this->next);
		if (this->next)
			this->next->function(this->next->next);
	}
	_file().close(this->fd);
	_command().delete(this);
}
