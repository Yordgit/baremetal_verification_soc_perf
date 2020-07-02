// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2000
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * Add to readline cmdline-editing by
 * (C) Copyright 2005
 * JinHua Luo, GuangDong Linux Center, <luo.jinhua@gd-linux.com>
 */

#include <common.h>
#include <cli.h>
#include <command.h>

#ifdef CONFIG_CMDLINE
/*
 * Run a command using the selected parser.
 *
 * @param cmd	Command to run
 * @param flag	Execution flags (CMD_FLAG_...)
 * @return 0 on success, or != 0 on error.
 */
int run_command(const char *cmd, int flag)
{
	/*
	 * cli_run_command can return 0 or 1 for success, so clean up
	 * its result.
	 */
	if (cli_simple_run_command(cmd, flag) == -1)
		return 1;

	return 0;
}

/*
 * Run a command using the selected parser, and check if it is repeatable.
 *
 * @param cmd	Command to run
 * @param flag	Execution flags (CMD_FLAG_...)
 * @return 0 (not repeatable) or 1 (repeatable) on success, -1 on error.
 */
int run_command_repeatable(const char *cmd, int flag)
{
	return cli_simple_run_command(cmd, flag);
}
#endif /* CONFIG_CMDLINE */

int run_command_list(const char *cmd, int len, int flag)
{
	int need_buff = 1;
	char *buff = (char *)cmd; /* cast away const */
	int rcode = 0;

	char temp_buf[1024] = { 0 }; /* temp for malloc */

	if (len == -1) {
		len = strlen(cmd);
#ifdef CONFIG_HUSH_PARSER
		/* hush will never change our string */
		need_buff = 0;
#else
		/* the built-in parser will change our string if it sees \n */
		need_buff = strchr(cmd, '\n') != NULL;
#endif
	}
	if (need_buff) {
		buff = temp_buf;
		if (!buff)
			return 1;
		memcpy(buff, cmd, len);
		buff[len] = '\0';
	}
#ifdef CONFIG_HUSH_PARSER
	rcode = parse_string_outer(buff, FLAG_PARSE_SEMICOLON);
#else
	/*
	 * This function will overwrite any \n it sees with a \0, which
	 * is why it can't work with a const char *. Here we are making
	 * using of internal knowledge of this function, to avoid always
	 * doing a malloc() which is actually required only in a case that
	 * is pretty rare.
	 */
#ifdef CONFIG_CMDLINE
	rcode = cli_simple_run_command_list(buff, flag);
#else
	rcode = 1;
#endif
#endif

	return rcode;
}

/****************************************************************************/

#if defined(CONFIG_CMD_RUN)
int do_run(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
	int i;

	if (argc < 2)
		return CMD_RET_USAGE;

	for (i = 1; i < argc; ++i) {
		char *arg;

		arg = env_get(argv[i]);
		if (arg == NULL) {
			printf("## Error: \"%s\" not defined\n", argv[i]);
			return 1;
		}

		if (run_command(arg, flag | CMD_FLAG_ENV) != 0)
			return 1;
	}
	return 0;
}
#endif

void cli_loop(void)
{
#ifdef CONFIG_CMDLINE
	cli_simple_loop();
#else
	printf("## Bst command line is disabled. Please enable CONFIG_CMDLINE\n");
#endif /*CONFIG_HUSH_PARSER*/
}

void cli_init(void)
{
#ifdef CONFIG_HUSH_PARSER
	bst_hush_start();
#endif

#if defined(CONFIG_HUSH_INIT_VAR)
	hush_init_var();
#endif
}
