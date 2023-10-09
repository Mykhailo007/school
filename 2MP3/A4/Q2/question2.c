/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DMY_MonthDY(char *buffer, const char *str);
void MonthDY_DMY(char *buffer, const char *str);

void DMY_MonthDY(char *buffer, const char *str){
    char months[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    char *endptr=str-1;
    int date[3]; //Day,Month,year
    for(int j=0;j<3;j++){
        date[j]=(int)strtol(endptr+1,&endptr,10);
    }
    snprintf(buffer,19, "%-10s%2d, %4d",months[date[1]-1], date[0],date[2]);
}

void MonthDY_DMY(char *buffer, const char *str){
    const char MONTHS[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    char month[10]="";
    int convertedmonth;
    int date;
    int year;
    char *endptr;
    char strdate[3];
    char strmonth[3];
    char stryear[5];

    
    for(int i=0;i<9;i++){
        if(str[i]!=' '){
            month[i]=str[i];
        }
        else{
            break;
        }
    }
    for(int i=10;i<12;i++){ //Days
        if(str[i]!=' '){
            date=(int)strtol(str+i,&endptr,10);
            break;
        }
    }
    for(int i=14;i<19;i++){ //Years
        if(str[i]!=' '){
            year=(int)strtol(str+i,&endptr,10);
            break;
        }
    }
    for(int i=0;i<12;i++){
        if(!strcmp(&month,MONTHS+i)){
            convertedmonth=i+1;
            break;
        }
    }
    (date<10) ? snprintf(strdate,3,"0%d",date) : snprintf(strdate,3,"%d",date);
    (convertedmonth<10) ? snprintf(strmonth,3,"0%d",convertedmonth) : snprintf(strmonth,3,"%d",convertedmonth);
    if(year>=1000){
        snprintf(stryear,5,"%d",year);
    }
    else if(year>=100){
        snprintf(stryear,5,"0%d",year);
    }
    else if(year>=10){
        snprintf(stryear,5,"00%d",year);
    }
    else{
        snprintf(stryear,5,"000%d",year);
    }
  snprintf(buffer,11,"%s/%s/%s",strdate,strmonth,stryear);
}



*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DMY_MonthDY(char *buffer, const char *str);
void MonthDY_DMY(char *buffer, const char *str);

void DMY_MonthDY(char *buffer, const char *str){
    char months[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    char *end_ptr=str-1;
    int date[3]; //Day,Month,year
    for(int j=0;j<3;j++){
        date[j]=(int)strtol(end_ptr+1,&end_ptr,10);
    }
    snprintf(buffer,19, "%-10s%2d, %4d",months[date[1]-1], date[0],date[2]);
}

void MonthDY_DMY(char *buffer, const char *str){
    const char MONTHS[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    char month[10]="";
    int converted_month;
    int date;
    int year;
    char *end_ptr;
    char str_date[3];
    char str_month[3];
    char str_year[5];

    
    for(int i=0;i<9;i++){
        if(str[i]!=' '){
            month[i]=str[i];
        }
        else{
            break;
        }
    }
    for(int i=10;i<12;i++){ //Days
        if(str[i]!=' '){
            date=(int)strtol(str+i,&end_ptr,10);
            break;
        }
    }
    for(int i=14;i<19;i++){ //Years
        if(str[i]!=' '){
            year=(int)strtol(str+i,&end_ptr,10);
            break;
        }
    }
    for(int i=0;i<12;i++){
        if(!strcmp(&month,MONTHS+i)){
            converted_month=i+1;
            break;
        }
    }
    (date<10) ? snprintf(str_date,3,"0%d",date) : snprintf(str_date,3,"%d",date);
    (converted_month<10) ? snprintf(str_month,3,"0%d",converted_month) : snprintf(str_month,3,"%d",converted_month);
    if(year>=1000){
        snprintf(str_year,5,"%d",year);
    }
    else if(year>=100){
        snprintf(str_year,5,"0%d",year);
    }
    else if(year>=10){
        snprintf(str_year,5,"00%d",year);
    }
    else{
        snprintf(str_year,5,"000%d",year);
    }
  snprintf(buffer,11,"%s/%s/%s",str_date,str_month,str_year);
}

int main(){
char format1[12][11] = { "01/01/1970"
                       , "10/02/1763"
                       , "15/03/0044"
                       , "18/04/1982"
                       , "05/05/1789"
                       , "06/06/1944"
                       , "01/07/1867"
                       , "03/08/1492"
                       , "02/09/1945"
                       , "24/08/1917"
                       , "11/11/1918"
                       , "08/12/1980"
                       };
char format2[12][19] = { "January    1, 1970" // First Day of History (according to computers)
                       , "February  10, 1763" // France cedes Canada to England
                       , "March     15,   44" // Assassination of Julius Caesar
                       , "April     18, 1982" // Canada Achieves Sovereignty 
                       , "May        5, 1789" // French Revolution
                       , "June       6, 1944" // D-Day Landings of WWII
                       , "July       1, 1867" // Confederation of Canada
                       , "August     3, 1492" // Christopher Columbus Sets Sail for the Americas
                       , "September  2, 1945" // WWII Surrender of Japan
                       , "October   24, 1917" // October Revolution (Julian Calendar)
                       , "November  11, 1918" // WWI Armistice
                       , "December   8, 1980" // Murder of John Lennon
                       };
    
    char buffer1[12][11];
    char buffer2[12][19];
    
    printf ("-- DD\\MM\\YY to Month DD, YYYY\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", format1[i]);
        DMY_MonthDY(buffer2[i], format1[i]);
        printf("-> \"%s\"\n", buffer2[i]);
    }
    
    
    printf ("\n\n-- Month DD, YYYY to DD\\MM\\YY\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", format2[i]);
        MonthDY_DMY(buffer1[i], format2[i]);
        printf("-> \"%s\"\n", buffer1[i]);
    }
}