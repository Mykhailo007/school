#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

float fkgrade(char str[]);

int syllables(char str[]){

    int len_str = strlen(str);
    int syllables = 0;

    for (int i = 0; i < len_str; i++){
        if (str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'){

            if (str[i+1]=='a'||str[i+1]=='e'||str[i+1]=='i'||str[i+1]=='o'||str[i+1]=='u'||str[i+1]=='A'||str[i+1]=='E'||str[i+1]=='I'||str[i+1]=='O'||str[i+1]=='U'){
                continue;
            }
            else{
                ++syllables;
            }
        }
    }
    return syllables;
}

float words(char str[]){
    float wordcount = 1;
    int isletter = 0;
    int i = 0;

   if (str[i]){
    while (str[i]){
        if (isletter && str[i]==' '){
            wordcount++;
            isletter = 0;
        }
        else if (isalpha(str[i])){
            isletter = 1;
        }
        i++;
    }
    return wordcount;
   }

    else{
        return 0;
    }    
}

float sentences(char str[]){
    float count = 0;
    int i = 0;
    while(str[i]){
        if (str[i] == '.' || str[i] == '!' || str[i] == '?'){
        ++count;}
        ++i;
    }
    return count;
}

float fkgrade(char str[]){
    float nmb_words = words(str);
    float nmb_syllables = syllables(str);
    float nmb_sentences = sentences(str);

    printf("\nsentences: %f, words: %f, syllables: %f\n", nmb_sentences, nmb_words, nmb_syllables);

    float difficulty = (0.39*(nmb_words/nmb_sentences)+11.8*(nmb_syllables/nmb_words));
    return difficulty;
}
/*

if (str[i] == 'A'){    
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'E'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'I'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'O'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'U'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                
                    else if (str[i] == 'a'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'e'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'i'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'o'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'u'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                        else{}

float fkgrade(char str[]){
    float words = 0;
    float sentences = 0;
    float syllables = 0;
    float difficulty;

    int i = 0;

    for (i = 0; str[i] != '\0'; i++){ //while the character selected is not /0

                    if (str[i] == 'A'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'E'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'I'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'O'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'U'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                
                    else if (str[i] == 'a'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'e'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'i'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'o'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    else if (str[i] == 'u'){
                        if (str[i-1] != 'A' && str[i-1] != 'E' && str[i-1] != 'I' && str[i-1] != 'O' && str[i-1] != 'U' && str[i-1] != 'a' && str[i-1] != 'e' && str[i-1] != 'i' && str[i-1] != 'o' && str[i-1] != 'u'){
                        ++syllables;}}
                    
        
        else if (isblank(str[i]) == 1){ //counting words 
            if (str[i-1] != )
            ++words;
        }

        else if (str[i] == '.' || str[i] == '!' || str[i] == '?'){
            ++sentences;
        }        
        // str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'
        // str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
       
        
    }
    printf("number of sentences %f, number of words %f, number of syllables %f", sentences, words, syllables);
    printf("\ni: %d\n", i);
    difficulty = (0.39*(words/sentences)+11.8*(syllables/words));
    return difficulty;
}
*/

int main() {
    char plato[] = "He who is the real tyrant, whatever men may think, is the real slave, and is obliged to practise the greatest adulation and servility, and to be the flatterer of the vilest of mankind.  He has desires which he is utterly unable to satisfy, and has more wants than any one, and is truly poor, if you know how to inspect the whole soul of him: all his life long he is beset with fear and is full of convulsions and distractions, even as the State which he resembles: and surely the resemblance holds?";

    char aurelius[] = "Nothing pertains to human beings except what defines us as human.  No other things can be demanded of us.  They aren't proper to human nature, nor is it incomplete without them.  It follows that they are not our goal, or what helps us reach it -- the good.  If any of them were proper to us, it would be improper to disdain or resist it.  If the things themselves were good, it could hardly be good to give them up.  But in reality, the more we deny ourselves such things (and things like them) -- or are deprived of them involuntarily, even -- the better we become.";

    char descartes[] = "I suppose, accordingly, that all the things which I see are false (fictitious); I believe that none of those objects which my fallacious memory represents ever existed; I suppose that I possess no senses; I believe that body, figure, extension, motion, and place are merely fictions of my mind.  What is there, then, that can be esteemed true?  Perhaps this only, that there is absolutely nothing certain.";
    
    char empty[] = "";
    
    printf("Plato...\nexpected sentences = 2\ne  xpected words = 94\n  expected syllables = 135\n");
    float out = fkgrade(plato);
    printf("> Reading Level = %f\n", out);
    printf("Marcus Aurelius...\n  expected sentences = 7\n   expected words = 104\n    expected syllables = 153\n");
    out = fkgrade(aurelius);
    printf("> Reading Level = %f\n", out);
    printf("Rene Descartes...\n  expected sentences = 3\n   expected words = 67\n    expected syllables = 113\n");
    out = fkgrade(descartes);
    printf("> Reading Level = %f\n", out);
    
    out = fkgrade(empty);
    printf("> Reading Level = %f\n", out);
}