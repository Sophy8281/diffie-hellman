
/*Difffie_Hellman key exchange, message encryption and decryption by;*/
        /**Sophy*/

#include <stdio.h>
#include<math.h>

// Power function to return value of a ^ b mod P
long long int power(long long int a, long long int b,
                                     long long int P)
{
    if (b == 1)
        return a;

    else
        return (((long long int)pow(a, b)) % P);
}

//Driver program

int main()
{
   int i, z; //Variables for message encryption and decryption
   char str[100];// A variable to hold the message
   long long int P, G, x, a, y, b, ka, kb; // Variables for key exchange

   printf("\n/*Difffie_Hellman key exchange, message encryption and decryption*/\n\n");
   // Both the persons will be agreed upon the public keys G and P
   P = 23; // A prime number P is taken
   printf("The value of P : %lld\n", P);
   G = 9; // A primitve root for P, G is taken
   printf("The value of G : %lld\n\n", G);

   printf("-------------------------------------------------------------\n");
   printf("\nPlease type message to Encrypt or Decrypt:\t");
   gets(str);
   printf("-------------------------------------------------------------\n");
   printf("\nPlease choose following options:\n");
   printf("1 = Encrypt the message(For Sender).\n");
   printf("2 = Decrypt the message(For Receiver).\n>>");
   scanf("%d", &z);
   printf("-------------------------------------------------------------\n");

   printf("\nfirst COMPUTE A SHARED SECRET KEY BY ENTERING THE FOLLOWING:-\n");

   // PERSON A will choose the private key a
   printf("The private key a for PERSON A:\n>>");
   scanf("%lld",&a);
   x = power(G, a, P); // gets the generated key


   // PERSON B will choose the private key b
   printf("The private key b for PERSON B:\n>>");
   scanf("%lld",&b);
   y = power(G, b, P); // gets the generated key

   // Generating the secret key after the exchange of keys
   ka = power(y, a, P); // Secret key for PERSON A
   kb = power(x, b, P); // Secret key for PERSON B

   printf("-------------------------------------------------------------\n");
   printf("<<<<<<<<<<<<Key generated successfully>>>>>>>>>>>>>>>>>>>>\n");
   printf("\nSecret key for the PERSON A is : %lld\n", ka);
   printf("Secret Key for the PERSON B is : %lld\n", kb);
   printf("-------------------------------------------------------------\n");

   //using switch case statements
   switch(z)
   {
   case 1:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + ka; //the key for encryption is 3 that is added to ASCII value

      printf("\nHaving the Secret key as %lld the Encrypted message is: %s\n", ka, str);
      printf("-------------------------------------------------------------\n");
      break;

   case 2:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - kb; //the key for encryption is 3 that is subtracted to ASCII value

      printf("\nHaving the Secret key as %lld the Decrypted message is : %s\n", kb, str);
      printf("-------------------------------------------------------------\n");

      break;

   default:
      printf("\nError\n");
   }
   return 0;
}
