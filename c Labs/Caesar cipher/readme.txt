1)General assumptions assumed to write the code:
    i)Encrytion/Decryption is case sensitive.
    ii)This code applies even for numbers in a cyclic manner(Eg:10 is 0,11 is 1 and so on..).
    iii)Special character don't get encrypted to ensure punctuations remain intact.
    iv)Input Key can be any number,but the used key for shift rotates in cyclic manner after 26 w.r.t alphabets and after 10 w.r.t numbers
    (Eg:27 is same as shift key 1 for alphabets and 11 is same as shift key 1 in case of numbers and so on)
    v)Encrytion is 'forward' shift of specified key.

2)Encrytion:
    i)E(x)=(x+n)%26 for alphabets.
    ii)E(x)=(x+n)%10 for numbers.
    iii)E(x)=x for special characters.

2)Decrytion:
    i)D(x)=(x-n)%26 for alphabets.
    ii)D(x)=(x-n)%10 for numbers.
    iii)D(x)=x for special characters.

3)Input of text to be encrypted/decrypted:
    To end the input process,press 'Tab' key of the keyboard 0and any other key to continue.
    [In the attempt to take even multiline paragraph input]

4)The code(including makefile) was written and run in windows.

5)However both formats of makefile:linux and windows are included in the folder.