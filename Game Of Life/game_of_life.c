/*
An implementation of the famous Game of Life
Coded by Samer Alkhabbaz
All Rights Saved (c)

Used Extended-ASCII Characters:
    129: ü
    179: │
    180: ┤
    191: ┐
    192: └
    193: ┴
    194: ┬
    195: ├
    196: ─
    197: ┼
    217: ┘
    218: ┌
    219: █
*/
#include <stdio.h>
#include <string.h>
#include <windows.h>

#define ROWS 8
#define COLS 12

void update_grid(int grid[ROWS][COLS]);

int get_surrounding_cells(int grid[ROWS][COLS], int row, int col);

void render(int grid[ROWS][COLS], int t);

void fancy_render(int grid[ROWS][COLS], int t, char *offset_left, char *offset_top);

int main(void) {
/*
	int grid[ROWS][COLS] = {
        {1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,1,1,1,0,0,0,0,1},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,1,1,0,0},
		{0,0,0,0,1,0,0,0,1,1,0,0},
		{0,0,0,1,0,0,0,0,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0}
    };
*/

/*
	int grid[ROWS][COLS] = {
        {1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,1,1,1,0,0,0,0,1},
        {0,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,1,0,0,0,0},
        {0,0,0,0,0,1,0,0,1,1,0,0},
        {0,0,0,0,1,0,0,0,1,1,0,1},
        {0,0,0,1,0,0,0,0,1,1,1,0},
        {1,1,0,0,0,0,0,0,0,0,0,1}
    };
*/

/**/
    int grid[ROWS][COLS] = {
        {1,0,0,0,0,0,0,0,0,1,0,1},
        {1,0,0,0,1,1,1,0,1,0,0,1},
        {0,0,0,1,1,0,0,1,0,0,0,0},
        {0,0,1,0,1,0,0,1,0,0,0,0},
        {1,1,0,1,0,1,1,0,1,1,1,1},
        {0,0,0,0,1,0,1,0,1,1,0,1},
        {0,0,0,1,0,0,1,0,1,1,1,0},
        {1,1,0,0,0,1,1,0,0,0,0,1}
    };
/**/

/*
	int grid[ROWS][COLS] = {
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1}
    };
*/

/*
	int grid[ROWS][COLS] = {
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,1,0,0,0,0},
        {0,0,0,0,0,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
    };
*/

/*
	int grid[ROWS][COLS] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
*/

    int console_length, console_width;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    console_length = (csbi.srWindow.Right - csbi.srWindow.Left + 1);
    console_width = (csbi.srWindow.Bottom - csbi.srWindow.Top + 1);

    #define OFFSET_LEFT ( (console_length - (5 * COLS + 1)) >> 1 )
    #define OFFSET_TOP ( (console_width - (2 * ROWS + 1)) >> 1 )

    char offset_left[OFFSET_LEFT + 1];
    char offset_top[OFFSET_TOP + 1];

    for (int i = 0; i < OFFSET_LEFT; i++) {
            offset_left[i] = ' ';
    }
    offset_left[OFFSET_LEFT] = '\0';

    for (int i = 0; i < OFFSET_TOP; i++) {
            offset_top[i] = '\n';
    }
    offset_top[OFFSET_TOP] = '\0';


    int t = 0; //time
    char c, option;
    printf("Infos:\n");
    printf("\tDr%ccke die Eingabetaste, um t zu inkrementieren\n\tTippe (q)uit, um das Programm zu beenden\n\n", 129);
    printf("Eingabetaste dr%ccken, um fortzufahren...", 129);
    getchar();

    printf("\n\n\nAnzeigeoptionen:\n");
    printf("\t1 = minimalistisches Design (ASCII)\n\t2 = gut aussehendes Design (Extended-ASCII)\n\n");
    printf("Tippe 1 oder 2: ");
    fflush(stdin);// empty the buffer (in case the user has entered more characters than expected)
    option = getchar();

    while (1) {
        if (option == '1')
            render(grid, t);
        else
            fancy_render(grid, t, offset_left, offset_top);

        fflush(stdin);
        c = getchar(); //Pause and wait for the user to press ENTER
        if (c == 'q')
            break;

        update_grid(grid);
        t++;
    }

    return 0;
}

void update_grid(int grid[ROWS][COLS]) {

    int new_grid[ROWS][COLS];

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {

            switch (get_surrounding_cells(grid, row, col)) {
                case 2:
                    new_grid[row][col] = grid[row][col];
                    break;
                case 3:
                    new_grid[row][col] = 1;
                    break;
                default:
                    new_grid[row][col] = 0;
            }

        }
    }

    memcpy(grid, new_grid, sizeof new_grid);
}

int get_surrounding_cells(int grid[ROWS][COLS], int row, int col) {
    return (
        grid[ row ? row-1 : ROWS-1 ][ col ? col-1 : COLS-1 ]  +
        grid[ row ? row-1 : ROWS-1 ][ col ]  +
        grid[ row ? row-1 : ROWS-1 ][ (col == COLS-1) ? 0 : col+1 ]  +

        grid[ row ][ col ? col-1 : COLS-1 ]  +
        grid[ row ][ (col == COLS-1) ? 0 : col+1 ]  +

        grid[ row == ROWS-1 ? 0 : row+1 ][ col ? col-1 : COLS-1 ]  +
        grid[ (row == ROWS-1) ? 0 : row+1 ][ col ]  +
        grid[ (row == ROWS-1) ? 0 : row+1 ][ (col == COLS-1) ? 0 : col+1 ]
    );
}

void render(int grid[ROWS][COLS], int t) {
    printf("\n\t t = %d\n\t", t);
    for (int i = 0; i < 2*COLS+3; i++)
        printf("-");
    printf("\n");
    for (int row = 0; row < ROWS; row++) {
        printf("\t| ");

        for (int col = 0; col < COLS; col++) {
            if (grid[row][col])
                printf("# ");
            else
                printf("  ");
        }
        printf("|\n");
    }
    printf("\t");
    for (int i = 0; i < 2*COLS+3; i++)
        printf("-");
    printf("\n");
}

void fancy_render(int grid[ROWS][COLS], int t, char *offset_left, char *offset_top) {
    char buffer[ROWS*COLS*20];
    char *buffer_ptr = buffer;

    buffer_ptr += sprintf(buffer_ptr, "%s", offset_top);
    buffer_ptr += sprintf(buffer_ptr, "%s%c", offset_left, 218);
    for (int i = 0; i < COLS; i++)
        buffer_ptr += sprintf(buffer_ptr, "%c%c%c%c%c", 196, 196, 196, 196, (i == COLS - 1 ? 191 : 194));

    for (int row = 0; row < ROWS; row++) {
        buffer_ptr += sprintf(buffer_ptr, "\n%s%c", offset_left, 179);

        for (int col = 0; col < COLS; col++) {
            if (grid[row][col])
                buffer_ptr += sprintf(buffer_ptr, " %c%c %c", 219, 219, 179);
            else
                buffer_ptr += sprintf(buffer_ptr, "    %c", 179);
        }

        if (row != ROWS - 1) {
            buffer_ptr += sprintf(buffer_ptr, "\n%s%c", offset_left, 195);
            for (int i = 0; i < COLS; i++)
                buffer_ptr += sprintf(buffer_ptr, "%c%c%c%c%c", 196, 196, 196, 196, (i == COLS - 1 ? 180 : 197));
        }
    }

    buffer_ptr += sprintf(buffer_ptr, "\n%s%c", offset_left, 192);
    for (int i = 0; i < COLS; i++)
        buffer_ptr += sprintf(buffer_ptr, "%c%c%c%c%c", 196, 196, 196, 196, (i == COLS - 1 ? 217 : 193));

    buffer_ptr += sprintf(buffer_ptr, "\n%s%s", offset_top, offset_left);
    for (int i = 0; i < ((5 * COLS + 1) >> 1) - 3; i++) //3 is the half length of "t = xy"
        buffer_ptr += sprintf(buffer_ptr, " ");
    buffer_ptr += sprintf(buffer_ptr, "t = %d", t);

    printf("%s", buffer);
}
