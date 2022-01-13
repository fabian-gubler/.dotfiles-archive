/* user and group to drop privileges to */
static const char *user  = "fabian";
static const char *group = "data";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#2E2E2E",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
