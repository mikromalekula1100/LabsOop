#include "line_editor.h"


string replace(string& text, int n, char old_value, char new_value)
{
     if(text.size() < n || n <= 0 ) return text;
    
    int64_t count_of_old_value = 0;

    for(int i = 0; i < text.size(); ++i){

        if(text[i] == old_value){

            count_of_old_value++;

            if(count_of_old_value % n == 0){

                text[i] = new_value;

            }

        } 
        
    }

    return text;
}
