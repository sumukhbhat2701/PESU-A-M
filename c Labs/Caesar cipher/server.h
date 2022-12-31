//To display executable options available:
void display_menu(void);

/*
To Encrypt message using encrytion function E:
  1)For alphabets(case sensitive):E(x)=(x+n)%26
  2)For numbers                  :E(x)=(x+n)%10
  3)For special charactes        :E(x)=x
*/
char* encrypt_message(char *plain_text,int key);

/*
To Decrypt message using decrytion function D:
  1)For alphabets(case sensitive):D(x)=(x-n)%26
  2)For numbers                  :D(x)=(x-n)%10
  3)For special charactes        :D(x)=x
*/
char* decrypt_message(char *encrypted_text,int key);

//Function to read input text(paragraph/word/sentence) terminated by 'Tab' key on keyboard:
char* read_text(char *text);

//Get a dahed line after every process to get a neat output:
void dashed_line(void);