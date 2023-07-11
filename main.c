/*
Locky Terminal 64-bit

Copyright (C) 2023 Special-Niewbie Softwares

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation version 3.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define MIN_PASSWORD_LEN 4
#define MAX_PASSWORD_LEN 120

// Caratteri consentiti per le password
char allowed_chars[256];
int allowed_chars_len = 0;

// Dichiarazione della funzione per verificare se il nome del file � valido
int is_valid_filename(const char *filename);

char *generate_password(const char *username, size_t len, bool include_lowercase, bool include_uppercase, bool include_numbers, bool include_symbols){
	
    const char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char number_chars[] = "0123456789";
	const char symbol_chars[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	int allowed_chars_len = 0;
	int password_len = 0;
	char password[MAX_PASSWORD_LEN + 1];
	

if (include_lowercase) {
for (int i = 0; i < strlen(lowercase_chars); i++) {
allowed_chars[(allowed_chars_len)++] = lowercase_chars[i];
}
}
if (include_uppercase) {
for (int i = 0; i < strlen(uppercase_chars); i++) {
allowed_chars[(allowed_chars_len)++] = uppercase_chars[i];
}
}
if (include_numbers) {
for (int i = 0; i < strlen(number_chars); i++) {
allowed_chars[(allowed_chars_len)++] = number_chars[i];
}
}
if (include_symbols) {
for (int i = 0; i < strlen(symbol_chars); i++) {
allowed_chars[(allowed_chars_len)++] = symbol_chars[i];
}
}

// Includi i caratteri casuali alla fine della password
while (password_len < len) {
password[password_len++] = allowed_chars[rand() % allowed_chars_len];
}

// Aggiungi il carattere di terminazione alla fine della password
password[password_len] = '\0';

// Mescola i caratteri nella password
for (int i = 0; i < password_len; i++) {
int j = rand() % password_len;
char temp = password[i];
password[i] = password[j];
password[j] = temp;
}

char *res = malloc((password_len + 1) * sizeof(char));
strcpy(res,password);
return res;
}

int main(int argc, char *argv[]) {
                                                                                
printf("\033[1mLOCKY TERMINAL 64-bit ver. 1.0 \033[0m      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
printf("\t           by               @@#                                               @@\n");
printf("\t    @@@@@   \033[1mSpecial-Niewbie\033[0m @@,     @*   @.        @*   @.        @*   @      @@\n");
printf("\t &@@@  *@@@.                @@,     @@@/@@,        @@@*@@,        @@@/@@.     @@\n");
printf("\t/@@      .@@@@@@@@@@@@*     @@,  &@@@@@@@@@@@   @@@@@@@@@@@@   &@@@@@@@@@@@   @@\n");
printf("\t.@@      ,@@(((@@@&@@(      @@,   ,,,@@@@/,,.    ,,,@@@@*,,.    ,,,@@@@/,,.   @@\n");
printf("\t *@@@@(@@@@    &@@%@@       @@,     @@% @@@        @@% @@&        @@# @@@     @@\n");
printf("\t    *@@@.          @/       @@,                                               @@\n");
printf("\t                            @@@                                              ,@@\n");
printf("\t                             #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
                                                                                
printf("\033[1m*******************************************************************************************************************\033[0m\n");
printf("\033[1m*\033[0m I truly appreciate you using my products and if you find them useful for your privacy needs or daily usage,     \033[1m*\033[0m\n"); 
printf("\033[1m*\033[0m a small donation as a friendly gesture would greatly help me to continue improving and providing valuable       \033[1m*\033[0m\n");
printf("\033[1m*\033[0m privacy tools for the future. I am grateful for your belief in my mission and for choosing to support me.       \033[1m*\033[0m\n");
printf("\033[1m*\033[0m For more info on how to Donate through through PayPal or Ko-fi, please visit my GitHub profile at:              \033[1m*\033[0m\n");
printf("\033[1m*\033[0m                    \033[1m            --- https://github.com/Special-Niewbie ---        \033[0m                               \033[1m*\033[0m\n"); 
printf("\033[1m*****************************************************************************************************************\033[0m\n\n");
start:
	srand(time(0));
	char username[256];
	char input[256];
	int len;
   // Richiede all'utente di inserire il nome utente
   printf(" Write a \033[1mUsername:\033[0m ");
   fgets(username, 256, stdin);
   // Rimuovi il carattere di nuova riga dalla stringa letta
   username[strcspn(username, "\r\n")] = 0;
   //Dichiarazione per il while
   bool valid_input = false;

// Richiedi all'utente di inserire la lunghezza desiderata della password
while (!valid_input) {
    printf("\n Write the length of the \033[1mPassword\033[0m (\033[1mfrom\033[0m \033[1;32m%d\033[0m \033[1mto\033[0m \033[1;32m%d\033[0m): ", MIN_PASSWORD_LEN, MAX_PASSWORD_LEN);
    fgets(input, 256, stdin);
    len = atoi(input);
    if (len >= MIN_PASSWORD_LEN && len <= MAX_PASSWORD_LEN) {
        valid_input = true;
    }
    else {
        printf(" \033[31;40m!!!\033[0mThe Password length is invalid. Please, insert a number from 4 to 120! \n");
    }
}
    
bool include_lowercase = false;
bool include_uppercase = false;
bool include_numbers = false;
bool include_symbols = false;

// Richiedi all'utente di scegliere quali caratteri includere nella password
valid_input = false;
printf("\n Include lowercase characters in password? (Y/n): ");
while (!valid_input) {
    fgets(input, 4, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strcmp(input, "Y") == 0) {
    	printf("\033[1;32m\t\t\tlowercase\033[0m\n");
        include_lowercase = true;
        valid_input = true;
    } else if (strcmp(input, "n") == 0) {
    	printf("\033[31;40m\t\t\tlowercase\033[0m\n");
        include_lowercase = false;
        valid_input = true;
    } else {
        printf(" \033[31;40m!!!\033[0mInvalid input. Insert 'Y'(yes) or 'n'(no): ");
    }
}
valid_input = false;
printf(" Include UPPERCASE characters in password? (Y/n): ");
while (!valid_input) {
    fgets(input, 4, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strcmp(input, "Y") == 0) {
    	printf("\033[1;32m\t\t\tUPPERCASE\033[0m\n");
        include_uppercase = true;
        valid_input = true;
    } else if (strcmp(input, "n") == 0) {
    	printf("\033[31;40m\t\t\tUPPERCASE\033[0m\n");
        include_uppercase = false;
        valid_input = true;
    } else {
        printf(" \033[31;40m!!!\033[0mInvalid input. Insert 'Y'(yes) or 'n'(no): ");
    }
}
valid_input = false;
printf(" Include Numbers in Password? (Y/n): ");
while (!valid_input) {
    fgets(input, 4, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strcmp(input, "Y") == 0) {
    	printf("\033[1;32m\t\t\tNumbers\033[0m\n");
        include_numbers = true;
        valid_input = true;
    } else if (strcmp(input, "n") == 0) {
    	printf("\033[31;40m\t\t\tNumbers\033[0m\n");
        include_numbers = false;
        valid_input = true;
    } else {
        printf(" \033[31;40m!!!\033[0mInvalid input. Insert 'Y'(yes) or 'n'(no): ");
    }
}
valid_input = false;
printf(" Include Symbols in password? (Y/n): ");
while (!valid_input) {
    fgets(input, 4, stdin);
    input[strcspn(input, "\n")] = 0;
    if (strcmp(input, "Y") == 0) {
    	printf("\033[1;32m\t\t\tSymbols\033[0m\n");
        include_symbols = true;
        valid_input = true;
    } else if (strcmp(input, "n") == 0) {
    	printf("\033[31;40m\t\t\tSymbols\033[0m\n");
        include_symbols = false;
        valid_input = true;
    } else {
        printf(" \033[31;40m!!!\033[0mInvalid input. Insert 'Y'(yes) or 'n'(no): ");
    }
}

char *password = generate_password(username, len, include_lowercase, include_uppercase, include_numbers, include_symbols);
// Utilizza un ciclo while per continuare a chiedere all'utente di inserire un valore valido per la lunghezza della password finch� non lo fa
if (password) {
    printf("\n\n \033[1m---- Generated Password:\033[0m %s", password);
}
// Chiedi all'utente se vuole salvare la password in un file
printf("\n\n Do you want to save the password in a file? (Y/n): ");
char save_choice[3];
scanf("%s", save_choice);
int c;
while ((c = getchar()) != '\n' && c != EOF);
if (strcmp(save_choice, "Y") != 0 && strcmp(save_choice, "n") != 0) {
    printf(" \033[31;40m!!!\033[0mPlease, enter valid input '\033[1;32mY\033[0m'(yes) or '\033[31;40mn\033[0m'(no): ");
    scanf("%s", save_choice);
    while ((c = getchar()) != '\n' && c != EOF);
}
// Opzione in caso di selezione NO ************
char opzione[6];
if (strcmp(save_choice, "n") == 0) {
    printf("\n\n Do you want to close the program or generate a new Username and Password? '\033[1;32mN\033[0m'(new) or '\033[31;40mc\033[0m'(close): ");
    do {
    // Azzera il buffer di "opzione" prima di leggere l'input dell'utente
    memset(opzione, 0, sizeof(opzione));
    scanf("%s", opzione);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (strcmp(opzione, "c") != 0 && strcmp(opzione, "N") != 0) {
        printf(" \033[31;40m!!!\033[0mInvalid input. Insert '\033[1;32mN\033[0m'(new) or '\033[31;40mc\033[0m'(close): ");
    }
} while (strcmp(opzione, "c") != 0 && strcmp(opzione, "N") != 0);

// Chiude il programma o genera un nuovo username e password in base alla scelta dell'utente
if (strcmp(opzione, "c") == 0) {
    // esegui il codice per chiudere il programma
    return 0;
} else if (strcmp(opzione, "N") == 0) {
	printf("\n");
    goto start;
}
// Libera la memoria allocata per la password
free(password);

return 0;
}
// Opzione in caso di selezione SI ***************
// Verifica la scelta dell'utente e salva la password in un file se ha scelto si
else{
  (strcmp(save_choice, "Y") == 0);
  // Chiedi all'utente di inserire il nome del file
  printf(" \033[1mEnter the file name:\033[0m ");
  char filename[265];
  fgets(filename, 265, stdin);
  
  // Rimuovi il carattere di nuova riga dal nome del file
  filename[strcspn(filename, "\n")] = 0;

  // Verifica che il nome del file sia valido
  if (!is_valid_filename(filename) && strcmp(strrchr(filename, '.'), ".txt")) {
    fprintf(stderr, " \033[31;40m!!!\033[0mInvalid filename. Enter a valid name:\n");
    return 1;
  }

  // Apri il file in modalit� di scrittura
  char filename_with_ext[265];
  sprintf(filename_with_ext, "%s.txt", filename);
  FILE *file = fopen(filename_with_ext, "w+");
  if (file == NULL) {
    perror(" Error opening file");
    return 1;
  }

  // Scrivi la password nel file
  fprintf(file, "Username: \n%s\n\nPassword: \n%s", username, password);

  // Chiudi il file
  fclose(file);

  printf("\n\n \033[1m###############  C o n g r a t u l a t i o n  ###############\n\n Username and Password saved in the file:\033[0m `%s`\n", filename_with_ext);
  
  // Chiedi all'utente se vuole chiudere il programma o generare un nuovo username e password
  printf("\n\nDo you want to close the program or generate a new Username and Password? '\033[1;32mN\033[0m'(new) or '\033[31;40mc\033[0m'(close): ");
char opzione[6];

do {
    // Azzera il buffer di "opzione" prima di leggere l'input dell'utente
    memset(opzione, 0, sizeof(opzione));
    scanf("%s", opzione);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (strcmp(opzione, "c") != 0 && strcmp(opzione, "N") != 0) {
        printf(" \033[31;40m!!!\033[0mInvalid input. Insert '\033[1;32mN\033[0m'(new) or '\033[31;40mc\033[0m'(close):  ");
    }
} while (strcmp(opzione, "c") != 0 && strcmp(opzione, "N") != 0);

// Chiudi il programma o genera un nuovo username e password in base alla scelta dell'utente
if (strcmp(opzione, "c") == 0) {
    // esegui il codice per chiudere il programma
    return 0;
} else if (strcmp(opzione, "N") == 0) {
	printf("\n");
    goto start;
}
// Libera la memoria allocata per la password
free(password);

return 0;
	}

}

int is_valid_filename(const char *filename) {
    // Verifica che il nome del file non sia troppo lungo
    if (strlen(filename) > 260) {
        return 0;
    }
    // Verifica che il nome del file non contenga caratteri non validi
    for (size_t i = 0; i < strlen(filename); i++) {
        if (!isalnum(filename[i]) && !isspace(filename[i]) && filename[i] != '.') {
            return 0;
        }
    }
    return 1;
}
