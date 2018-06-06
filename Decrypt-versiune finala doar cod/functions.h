int search_row(char key,char row[11]);
int identify( char key ,char row_1[] ,char row_2[] ,char row_3[], int *row_number);
void print_encrypted(char message[] ,char row_1[] ,char row_2[] ,char row_3[] ,int message_id[] ,int row_number[]);
void find_message_id(int *message_id,int position , int row_number);