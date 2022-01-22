#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Bug : Can't check user input instruction that is allowed.
int game[4][4];

void new_game();
void generation_num();
void flash_array();
void instruction();

void count_section(char); //(array,now_array,x_ray,y_ray) 00:up 01:down 10:left 11:right 

/*
00 01
10 11
*/

void main(){
	new_game();
	while(1){
		generation_num();
		flash_array();
		instruction();
	}
}

void new_game(){
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			game[i][j]=0;
		}
	}
}

void generation_num(){
	srand(time(NULL));
	int i=0,j=0;
	
	while(1){
		i=rand()%4;
		j=rand()%4;
		if(game[i][j]==0){
			game[i][j]=(rand()%2+1)*2;
			//printf("\n(%2d,%2d)",i,j);
			//system("pause");
			break;
		}
	}
}

void flash_array(){
	int i=0,j=0;
	
	system("cls");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%10d",game[i][j]);
		}
		printf("\n");
    }
}

void instruction(){
	char direction;
	int error_input=1;
	while(error_input==1){
		scanf("%c",&direction);
		if((direction=='w')||(direction=='s')||(direction=='a')||(direction=='d'))
			error_input=0;
	}
	
	count_section(direction);
			
}

// count_list use tool
void clear_count_list(int*);
void write_count_list(int,int,int*);//(left or right, current_XorY_axis, list_array)
int count_zero(int*);
void move_list(int,int,int*); //(left or right, zero number, list_array)
void count(int,int*); //(left or right,list_array)
void writeback_array(int,int,int*);


void count_section(char inst){
	int i=0,j=0,z=0;
	int zero_number=0;
	int count_list[4];
		
	switch(inst){
		case 'w':
			clear_count_list(count_list);
			for(i=0;i<4;i++){
		
				write_count_list(0,i,count_list);
				zero_number = count_zero(count_list);
				move_list(0,zero_number,count_list);
				count(0,count_list);
				move_list(0,zero_number,count_list);
				writeback_array(0,i,count_list);
				clear_count_list(count_list);
				
			}
			break;
		case 's':
			clear_count_list(count_list);
			for(i=0;i<4;i++){
		
				write_count_list(0,i,count_list);
				zero_number = count_zero(count_list);
				move_list(1,zero_number,count_list);
				count(1,count_list);
				move_list(1,zero_number,count_list);
				writeback_array(0,i,count_list);
				clear_count_list(count_list);
				
			}
			break;
		case 'a':
			clear_count_list(count_list);
			for(i=0;i<4;i++){
		
				write_count_list(1,i,count_list);
				zero_number = count_zero(count_list);
				move_list(0,zero_number,count_list);
				count(0,count_list);
				move_list(0,zero_number,count_list);
				writeback_array(1,i,count_list);
				clear_count_list(count_list);
				
			}
			break;
		case 'd':
			clear_count_list(count_list);
			for(i=0;i<4;i++){
		
				write_count_list(1,i,count_list);
				zero_number = count_zero(count_list);
				move_list(1,zero_number,count_list);
				count(1,count_list);
				move_list(1,zero_number,count_list);
				writeback_array(1,i,count_list);
				clear_count_list(count_list);
				
			}
			break;
		default:
			break;	
	}		
}

void clear_count_list(int* list){
	int j=0;
	for(j=0;j<4;j++){					
		list[j]=0;	
	}
}

void write_count_list(int type,int axis,int* list){
	int j=0;
	//colume
	if(type==0){
		for(j=0;j<4;j++){
			list[j]=game[j][axis];
		}
	}
	//row
	else{
		for(j=0;j<4;j++){
			list[j]=game[axis][j];
		}
	}
}

int count_zero(int* list){
	int i=0,zero_number=0;
	for(i=0;i<4;i++){
		if(list[i]==0){
			zero_number=zero_number+1; 
		}
	}
	return zero_number;
}

void move_list(int type,int zero_number,int* count_list){
	int i=0,j=0,z=0;
	int temp=0;
	if(type==0){
		if(zero_number==4){
			
		}
		else{
			j=0;
			for(;zero_number>0;zero_number--){
				for(i=j;i<4;i++){
					if(count_list[i]==0){
						for(z=0;z<3;z++){
							if(count_list[z]==0){
								temp = count_list[z];
								count_list[z]=count_list[z+1];
								count_list[z+1]=temp;
							}
						}
					}					
				}
			}
		}
	}
	else{
		if(zero_number==4){
		
		}
		else{
			j=0;
			for(;zero_number>0;zero_number--){
				for(i=j;i<4;i++){
					if(count_list[i]==0){
						for(z=3;z>0;z--){
							if(count_list[z]==0){
								temp = count_list[z-1];
								count_list[z-1]=count_list[z];
								count_list[z]=temp;
							}
						}
					}					
				}
			}
		}
	}
}

void count(int type,int* count_list){
	int z=0;
	if(type==0){			
		for(z=0;z<3;z++){
			if(count_list[z]==count_list[z+1]){
				count_list[z]=count_list[z]+count_list[z+1];
				count_list[z+1]=0;
			}
		}
	}
	else{					
		for(z=3;z>0;z--){
			if(count_list[z]==count_list[z-1]){
				count_list[z]=count_list[z]+count_list[z-1];
				count_list[z-1]=0;
			}
		}

	}
}

void writeback_array(int type,int axis,int* count_list){
	int j=0;
	if(type==0){
		for(j=0;j<4;j++){
			game[j][axis]=count_list[j];
		}
	}
	else{
		for(j=0;j<4;j++){
			game[axis][j]=count_list[j];
		}
	}
}

