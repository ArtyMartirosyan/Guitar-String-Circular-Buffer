# Guitar-String-Circular-Buffer

This program focuses on replicating the sound of a guitar by pressing keys on the keyboard. 
I created a circular buffer class that has a vector of int16_t which basically had all the properties of circular buffer.
I also made some test cases with the BOOST library to test the circular buffer class. 
Then, I used this circular buffer to create white noise by assigning it a decaying random number to create the vibration string and then by using the audio library of SFML 
I combined the frequencies corresponding to standard notes (A,B, C, D etc.) and the circular buffer to replicate a guitar string. 
All of the code was later checked with cpplint.py to check the formatting of the code so that it’s standardized with Google’s standards. 
