/*
 * main.c
 *
 *  Created on: Feb 10, 2016
 *      Author: Mohammad
 */


#include "stdio.h"

#define STUDENTS_ARRAY_SIZE 200U


typedef struct
{
	unsigned char   student_number;
	char*           student_name;
	unsigned char   student_age;
}s2;

static s2 students[STUDENTS_ARRAY_SIZE]=
{{.student_number=1,.student_name="Abida",.student_age=13 }
,{.student_number=2,.student_name="Adiba",.student_age=14 }
,{.student_number=3,.student_name="Afaf",.student_age=15 }
,{.student_number=4,.student_name="Afifa",.student_age=13 }
,{.student_number=5,.student_name="Ahlem",.student_age=14 }
,{.student_number=6,.student_name="Aicha",.student_age=15 }
,{.student_number=7,.student_name="Aida",.student_age=13 }
,{.student_number=8,.student_name="Alia",.student_age=14 }
,{.student_number=9,.student_name="Amana",.student_age=15 }
,{.student_number=10,.student_name="Amel",.student_age=13 }
,{.student_number=11,.student_name="Amina",.student_age=14 }
,{.student_number=12,.student_name="Amira",.student_age=15 }
,{.student_number=13,.student_name="Anissa",.student_age=13 }
,{.student_number=14,.student_name="Asma",.student_age=14 }
,{.student_number=15,.student_name="Assia",.student_age=15 }
,{.student_number=16,.student_name="Atika",.student_age=13 }
,{.student_number=17,.student_name="Aya",.student_age=14 }
,{.student_number=18,.student_name="Aziza",.student_age=15 }
,{.student_number=19,.student_name="Badra",.student_age=13 }
,{.student_number=20,.student_name="Basma",.student_age=14 }
,{.student_number=21,.student_name="Douha",.student_age=15 }
,{.student_number=22,.student_name="Dounia",.student_age=13 }
,{.student_number=23,.student_name="Emna",.student_age=14 }
,{.student_number=24,.student_name="Fadila",.student_age=15 }
,{.student_number=25,.student_name="Faiza",.student_age=13 }
,{.student_number=26,.student_name="Farida",.student_age=14 }
,{.student_number=27,.student_name="Faten",.student_age=15 }
,{.student_number=28,.student_name="Hadia",.student_age=13 }
,{.student_number=29,.student_name="Hafida",.student_age=14 }
,{.student_number=30,.student_name="Hafsa",.student_age=15 }
,{.student_number=31,.student_name="Hania",.student_age=13 }
,{.student_number=32,.student_name="Hanna",.student_age=14 }
,{.student_number=33,.student_name="Hayet",.student_age=15 }
,{.student_number=34,.student_name="Hawa",.student_age=13 }
,{.student_number=35,.student_name="Ikram",.student_age=14 }
,{.student_number=36,.student_name="Ilhem",.student_age=15 }
,{.student_number=37,.student_name="Imane",.student_age=13 }
,{.student_number=38,.student_name="Ines",.student_age=14 }
,{.student_number=39,.student_name="Karima",.student_age=15 }
,{.student_number=40,.student_name="Kenza",.student_age=13 }
,{.student_number=41,.student_name="Khadid",.student_age=14 }
,{.student_number=42,.student_name="Khalid",.student_age=15 }
,{.student_number=43,.student_name="Latifa",.student_age=13 }
,{.student_number=44,.student_name="Leila",.student_age=14 }
,{.student_number=45,.student_name="Maha",.student_age=15 }
,{.student_number=46,.student_name="Maissa",.student_age=13 }
,{.student_number=47,.student_name="Majda",.student_age=14 }
,{.student_number=48,.student_name="Malika",.student_age=15 }
,{.student_number=49,.student_name="Manel",.student_age=13 }
,{.student_number=50,.student_name="Meriem",.student_age=14 }
,{.student_number=51,.student_name="Moufid",.student_age=15 }
,{.student_number=52,.student_name="Mouna",.student_age=13 }
,{.student_number=53,.student_name="Mounir",.student_age=14 }
,{.student_number=54,.student_name="Nabila",.student_age=15 }
,{.student_number=55,.student_name="Nacira",.student_age=13 }
,{.student_number=56,.student_name="Nadia",.student_age=14 }
,{.student_number=57,.student_name="Nadjib",.student_age=15 }
,{.student_number=58,.student_name="Nafiss",.student_age=13 }
,{.student_number=59,.student_name="Naima",.student_age=14 }
,{.student_number=60,.student_name="Najet",.student_age=15 }
,{.student_number=61,.student_name="Nawel",.student_age=13 }
,{.student_number=62,.student_name="Naziha",.student_age=14 }
,{.student_number=63,.student_name="Nedjma",.student_age=15 }
,{.student_number=64,.student_name="Nour",.student_age=13 }
,{.student_number=65,.student_name="Rachid",.student_age=14 }
,{.student_number=66,.student_name="Rahma",.student_age=15 }
,{.student_number=67,.student_name="Rajah",.student_age=13 }
,{.student_number=68,.student_name="Rawda",.student_age=14 }
,{.student_number=69,.student_name="Safia",.student_age=15 }
,{.student_number=70,.student_name="Saida",.student_age=13 }
,{.student_number=71,.student_name="Sakina",.student_age=14 }
,{.student_number=72,.student_name="Saliha",.student_age=15 }
,{.student_number=73,.student_name="Salima",.student_age=13 }
,{.student_number=74,.student_name="Saloua",.student_age=14 }
,{.student_number=75,.student_name="Samia",.student_age=15 }
,{.student_number=76,.student_name="Samira",.student_age=13 }
,{.student_number=77,.student_name="Sanaa",.student_age=14 }
,{.student_number=78,.student_name="Selma",.student_age=15 }
,{.student_number=79,.student_name="Soraya",.student_age=13 }
,{.student_number=80,.student_name="Souad",.student_age=14 }
,{.student_number=81,.student_name="Wafa",.student_age=15 }
,{.student_number=82,.student_name="Wahiba",.student_age=13 }
,{.student_number=83,.student_name="Warda",.student_age=14 }
,{.student_number=84,.student_name="Wasill",.student_age=15 }
,{.student_number=85,.student_name="Wided",.student_age=13 }
,{.student_number=86,.student_name="Yamina",.student_age=14 }
,{.student_number=87,.student_name="Yasmin",.student_age=15 }
,{.student_number=88,.student_name="Yousra",.student_age=13 }
,{.student_number=89,.student_name="Zineb",.student_age=14 }
,{.student_number=90,.student_name="Zohra",.student_age=15 }
,{.student_number=91,.student_name="Adam",.student_age=13 }
,{.student_number=92,.student_name="Adel",.student_age=14 }
,{.student_number=93,.student_name="Adib",.student_age=15 }
,{.student_number=94,.student_name="Adil",.student_age=13 }
,{.student_number=95,.student_name="Ahmed",.student_age=14 }
,{.student_number=96,.student_name="Aissa",.student_age=15 }
,{.student_number=97,.student_name="Ali",.student_age=13 }
,{.student_number=98,.student_name="Amine",.student_age=14 }
,{.student_number=99,.student_name="Amir",.student_age=15 }
,{.student_number=100,.student_name="Anas",.student_age=13 }
,{.student_number=101,.student_name="Anise",.student_age=14 }
,{.student_number=102,.student_name="Anouar",.student_age=15 }
,{.student_number=103,.student_name="Ayoub",.student_age=13 }
,{.student_number=104,.student_name="Azziz",.student_age=14 }
,{.student_number=105,.student_name="Bachir",.student_age=15 }
,{.student_number=106,.student_name="Badr",.student_age=13 }
,{.student_number=107,.student_name="Baligh",.student_age=14 }
,{.student_number=108,.student_name="Billal",.student_age=15 }
,{.student_number=109,.student_name="Bouzid",.student_age=13 }
,{.student_number=110,.student_name="Chafik",.student_age=14 }
,{.student_number=111,.student_name="Chahid",.student_age=15 }
,{.student_number=112,.student_name="Chaker",.student_age=13 }
,{.student_number=113,.student_name="Chams",.student_age=14 }
,{.student_number=114,.student_name="Chawki",.student_age=15 }
,{.student_number=115,.student_name="Chokri",.student_age=13 }
,{.student_number=116,.student_name="Daoud",.student_age=14 }
,{.student_number=117,.student_name="Djamel",.student_age=15 }
,{.student_number=118,.student_name="Djilla",.student_age=13 }
,{.student_number=119,.student_name="Fadel",.student_age=14 }
,{.student_number=120,.student_name="Fahim",.student_age=15 }
,{.student_number=121,.student_name="Fares",.student_age=13 }
,{.student_number=122,.student_name="Farid",.student_age=14 }
,{.student_number=123,.student_name="Fathi",.student_age=15 }
,{.student_number=124,.student_name="Faudel",.student_age=13 }
,{.student_number=125,.student_name="Faouzi",.student_age=14 }
,{.student_number=126,.student_name="Faycal",.student_age=15 }
,{.student_number=127,.student_name="Ferhat",.student_age=13 }
,{.student_number=128,.student_name="Fouad",.student_age=14 }
,{.student_number=129,.student_name="Gibril",.student_age=15 }
,{.student_number=130,.student_name="Ghani",.student_age=13 }
,{.student_number=131,.student_name="Habib",.student_age=14 }
,{.student_number=132,.student_name="Hafid",.student_age=15 }
,{.student_number=133,.student_name="Hakim",.student_age=13 }
,{.student_number=134,.student_name="Halim",.student_age=14 }
,{.student_number=135,.student_name="Hamid",.student_age=15 }
,{.student_number=136,.student_name="Hani",.student_age=13 }
,{.student_number=137,.student_name="Hichem",.student_age=14 }
,{.student_number=138,.student_name="Hilal",.student_age=15 }
,{.student_number=139,.student_name="Hosni",.student_age=13 }
,{.student_number=140,.student_name="Ismail",.student_age=14 }
,{.student_number=141,.student_name="Imed",.student_age=15 }
,{.student_number=142,.student_name="Jabar",.student_age=13 }
,{.student_number=143,.student_name="Kaddou",.student_age=14 }
,{.student_number=144,.student_name="Kamel",.student_age=15 }
,{.student_number=145,.student_name="Karim",.student_age=13 }
,{.student_number=146,.student_name="Khaled",.student_age=14 }
,{.student_number=147,.student_name="Khalil",.student_age=15 }
,{.student_number=148,.student_name="Larbi",.student_age=13 }
,{.student_number=149,.student_name="Lotfi",.student_age=14 }
,{.student_number=150,.student_name="Mabrou",.student_age=15 }
,{.student_number=151,.student_name="Mahbou",.student_age=13 }
,{.student_number=152,.student_name="Mahfou",.student_age=14 }
,{.student_number=153,.student_name="Mahmou",.student_age=15 }
,{.student_number=154,.student_name="Malik",.student_age=13 }
,{.student_number=155,.student_name="Marwan",.student_age=14 }
,{.student_number=156,.student_name="Mehdi",.student_age=15 }
,{.student_number=157,.student_name="Mohame",.student_age=13 }
,{.student_number=158,.student_name="Moktar",.student_age=14 }
,{.student_number=159,.student_name="Moncef",.student_age=15 }
,{.student_number=160,.student_name="Mourad",.student_age=13 }
,{.student_number=161,.student_name="Nabil",.student_age=14 }
,{.student_number=162,.student_name="Nacer",.student_age=15 }
,{.student_number=163,.student_name="Nadir",.student_age=13 }
,{.student_number=164,.student_name="Nadjib",.student_age=14 }
,{.student_number=165,.student_name="Nassim",.student_age=15 }
,{.student_number=166,.student_name="Nazim",.student_age=13 }
,{.student_number=167,.student_name="Nouh",.student_age=14 }
,{.student_number=168,.student_name="Omar",.student_age=15 }
,{.student_number=169,.student_name="Othman",.student_age=13 }
,{.student_number=170,.student_name="Usama",.student_age=14 }
,{.student_number=171,.student_name="Rabah",.student_age=15 }
,{.student_number=172,.student_name="Rachid",.student_age=13 }
,{.student_number=173,.student_name="Rafik",.student_age=14 }
,{.student_number=174,.student_name="Rahal",.student_age=15 }
,{.student_number=175,.student_name="Ramzi",.student_age=13 }
,{.student_number=176,.student_name="Raouf",.student_age=14 }
,{.student_number=177,.student_name="Rayan",.student_age=15 }
,{.student_number=178,.student_name="Reda",.student_age=13 }
,{.student_number=179,.student_name="Redoua",.student_age=14 }
,{.student_number=180,.student_name="Riad",.student_age=15 }
,{.student_number=181,.student_name="Rochdi",.student_age=13 }
,{.student_number=182,.student_name="Sabri",.student_age=14 }
,{.student_number=183,.student_name="Salah",.student_age=15 }
,{.student_number=184,.student_name="Salim",.student_age=13 }
,{.student_number=185,.student_name="Sami",.student_age=14 }
,{.student_number=186,.student_name="Sedik",.student_age=15 }
,{.student_number=187,.student_name="Sofian",.student_age=13 }
,{.student_number=188,.student_name="Tahar",.student_age=14 }
,{.student_number=189,.student_name="Taimim",.student_age=15 }
,{.student_number=190,.student_name="Tarek",.student_age=13 }
,{.student_number=191,.student_name="Tayeb",.student_age=14 }
,{.student_number=192,.student_name="Tawfik",.student_age=15 }
,{.student_number=193,.student_name="Wallid",.student_age=13 }
,{.student_number=194,.student_name="Wassim",.student_age=14 }
,{.student_number=195,.student_name="Yacoub",.student_age=15 }
,{.student_number=196,.student_name="Yazid",.student_age=13 }
,{.student_number=197,.student_name="Youcef",.student_age=14 }
,{.student_number=198,.student_name="Younes",.student_age=15 }
,{.student_number=199,.student_name="Zahid",.student_age=13 }
,{.student_number=200,.student_name="Zakari",.student_age=14 }
};


int main()
{
	unsigned char i=0;
	printf("Hello Eclipse Regex :) \n");
	for(i=0;i<STUDENTS_ARRAY_SIZE;i++)
	{
		printf("Student number= %d, Student name= %s, Student age=%d \n",
				students[i].student_number,students[i].student_name,students[i].student_age);
	}

	return  0;

}
