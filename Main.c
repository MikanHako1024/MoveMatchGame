
/* 移动火柴游戏 */ 

// 精简 优化




// 游戏套路：
// 1.不改变符号只改变数字 
// 2.改变符号和数字 
// 3.不改变数字只改变符号 
// 4.？倒过来看 
// ps: 等号可 -成负号 -+成加号


#include <stdio.h>



int _PRIZM[10]={  // 二进制存 15位0/1 
/*0*/	31599, 	
/*1*/	4681, 
/*2*/	29671, 
/*3*/	29647, 
/*4*/	23497, 
/*5*/	31183, 
/*6*/	31215, 
/*7*/	31561, 
/*8*/	31727, 
/*9*/	31695, 
};

// 打印 
void Print(int num)
{
	if( num<0 || num>9 )return ;
	
	int k, n=_PRIZM[num], cnt=0;
	for(k=1<<(15-1); k>0; k>>=1)
		printf("%s%c", (k&n)?("■"):("  "), ((++cnt)%3==0)?('\n'):(' '));
	printf("\n"); 
}

//void PrintStr(


// 录字模 
int __ScanZM()
{
	int i, j, n=0; 
	char t;
	for(i=0; i<5; i++)
		for(j=0; j<3; j++)
		{
			do
			{
				scanf("%c", &t);
			}while( !(t=='1' || t=='0') );
			
			n=(n<<1)^(t-'0'); // (n<<1)+(t-'0');
		}
	printf("%d\n", n);
	return n;
}

void _ScanZM()
{
	int z, arr[10];
	for(z=0; z<=9; z++)
		arr[z]=__ScanZM();
	
	for(z=0; z<=9; z++)
		printf("%d ", arr[z]);
	printf("\n");
}

// 待 完成输出使用 Print 



int OPE[4][10][4]={

{ // DE[10][4]
/*0*/	{ 0 }, 
/*1*/	{ 0 }, 
/*2*/	{ 0 }, 
/*3*/	{ 0 }, 
/*4*/	{ 0 }, 
/*5*/	{ 0 }, 
/*6*/	{ 1, 5 }, 
/*7*/	{ 0 }, 
/*8*/	{ 3, 0, 6, 9 }, 
/*9*/	{ 2, 3, 5 }, 
}, 

{ // IN[10][4]
/*0*/	{ 1, 8 }, 
/*1*/	{ 0 }, 
/*2*/	{ 0 }, 
/*3*/	{ 1, 9 }, 
/*4*/	{ 0 }, 
/*5*/	{ 2, 6, 9 }, 
/*6*/	{ 1, 8 }, 
/*7*/	{ 0 }, 
/*8*/	{ 0 }, 
/*9*/	{ 1, 8 }, 
}, 

{ // MS[10][4]
/*0*/	{ 1, 0 }, 
/*1*/	{ 1, 1 }, 
/*2*/	{ 1, 2 }, 
/*3*/	{ 1, 3 }, 
/*4*/	{ 1, 4 }, 
/*5*/	{ 1, 5 }, 
/*6*/	{ 1, 6 }, 
/*7*/	{ 1, 7 }, 
/*8*/	{ 1, 8 }, 
/*9*/	{ 1, 9 }, 
}, 

{ // DEIN[10][4]
/*0*/	{ 2, 6, 9 }, 
/*1*/	{ 0 }, 
/*2*/	{ 1, 3 }, 
/*3*/	{ 2, 2, 5 }, 
/*4*/	{ 1, 7}, 
/*5*/	{ 1, 3 }, 
/*6*/	{ 2, 0, 9 }, 
/*7*/	{ 1, 4 }, 
/*8*/	{ 0 }, 
/*9*/	{ 2, 0, 6 }, 
} 

};



#define FOR_OPE(i) for(ope[i]=0; ope[i]<3; ope[i]++)
#define FOR_Z(i) for(z[i]=1; z[i]<=OPE[ope[i]][n[i]][0]; z[i]++)
#define NUM(i) (OPE[ope[i]][n[i]][z[i]])


/*
// 十以内的两个数的加 _ 对数字减增 ('+')
void _f1_1(int a, int b, int c) 
{
	int n[3]={a, b, c}; // a b c 
	int ope[3]; // opea opeb opec
	int z[3]; // za zb zc
	
	// 对两个数-+ 
	FOR_OPE(0)
	{
		FOR_OPE(1)
		{
			if( ope[1]==ope[0] )continue;
			FOR_OPE(2)
			{
				if( ope[2]==ope[0] )continue;
				if( ope[2]==ope[1] )continue;
				
				FOR_Z(0)FOR_Z(1)FOR_Z(2)
					if( NUM(0)+NUM(1)==NUM(2) )
						printf("%d + %d = %d \n", NUM(0), NUM(1), NUM(2));
			}
		}
	}
	
	// 对一个数-+ 
	int t;
	for(t=0; t<3; t++)
	{
		ope[0]=2; ope[1]=2; ope[2]=2;
		ope[t]=3;
		
		FOR_Z(0)FOR_Z(1)FOR_Z(2)
			if( NUM(0)+NUM(1)==NUM(2) )
				printf("%d + %d = %d \n", NUM(0), NUM(1), NUM(2));
	}
}

// 十以内的两个数的减 _ 对数字减增 ('-')
void _f1_2(int a, int b, int c) 
{
	int n[3]={a, b, c}; // a b c 
	int ope[3]; // opea opeb opec
	int z[3]; // za zb zc
	
	// 对两个数-+ 
	FOR_OPE(0)
	{
		FOR_OPE(1)
		{
			if( ope[1]==ope[0] )continue;
			FOR_OPE(2)
			{
				if( ope[2]==ope[0] )continue;
				if( ope[2]==ope[1] )continue;
				
				FOR_Z(0)FOR_Z(1)FOR_Z(2)
					if( NUM(0)-NUM(1)==NUM(2) )
						printf("%d - %d = %d \n", NUM(0), NUM(1), NUM(2));
			}
		}
	}
	
	// 对一个数-+ 
	int t;
	for(t=0; t<3; t++)
	{
		ope[0]=2; ope[1]=2; ope[2]=2;
		ope[t]=3;
		
		FOR_Z(0)FOR_Z(1)FOR_Z(2)
			if( NUM(0)-NUM(1)==NUM(2) )
				printf("%d - %d = %d \n", NUM(0), NUM(1), NUM(2));
	}
}


// 十以内的两个数的加 _ 对数字增 '+'减成'-' 
void _f2_1(int a, int b, int c) 
{
	int n[3]={a, b, c}; // a b c
	int ope[3]; // opea opeb opec
	int z[3]; // za zb zc
	
	int t;
	for(t=0; t<3; t++)
	{
		ope[0]=2; ope[1]=2; ope[2]=2;
		ope[t]=1;
		
		FOR_Z(0)FOR_Z(1)FOR_Z(2)
			if( NUM(0)-NUM(1)==NUM(2) )
				printf("%d - %d = %d \n", NUM(0), NUM(1), NUM(2));
	}
}

// 十以内的两个数的减 _ 对数字减 '-'加成'+' 
void _f2_2(int a, int b, int c) 
{
	int n[3]={a, b, c}; // a b c
	int ope[3]; // opea opeb opec
	int z[3]; // za zb zc
	
	int t;
	for(t=0; t<3; t++)
	{
		ope[0]=2; ope[1]=2; ope[2]=2;
		ope[t]=0;
		
		FOR_Z(0)FOR_Z(1)FOR_Z(2)
			if( NUM(0)+NUM(1)==NUM(2) )
				printf("%d + %d = %d \n", NUM(0), NUM(1), NUM(2));
	}
}

// 待 兼容合并

// 待 优化函数名 变量名 等 
*/


void _f(int a, int mod, int b, int c, int opemod) // a mod b = c 数字修改方式opemod (mod是改后或不改的符号)
{
	int n[3]={a, b, c}; // a b c
	int ope[3]; // opea opeb opec
	int z[3]; // za zb zc
	int t;
	
    if( opemod<0 || opemod>4 )
    { return -1; }
    else if( opemod==4 ) // 两数字-+
    {
    
	    // 一ope0 一ope1 一ope2
	    FOR_OPE(0)
		{
			FOR_OPE(1)
			{
				if( ope[1]==ope[0] )continue;
				FOR_OPE(2)
				{
					if( ope[2]==ope[0] )continue;
					if( ope[2]==ope[1] )continue;
					
					FOR_Z(0)FOR_Z(1)FOR_Z(2)
					    // ？
					    // ？改 if 为 三目运算
					    // ？...
						if( NUM(0)+((mod==2)?(-1):(1))*NUM(1)==NUM(2) )
							printf("%d %c %d = %d \n", NUM(0), (mod==2)?('-'):('+'), NUM(1), NUM(2));
				}
			}
		}
        
    }
    else if( opemod==3 ) // 一数字-+
    {
        
	    // 两ope2 一ope3
		for(t=0; t<3; t++)
		{
		    // ？
		    // ？两ope2 一ope3 即 一ope3 其他ope2
			ope[0]=2; ope[1]=2; ope[2]=2;
			ope[t]=3; // ope3
			
			FOR_Z(0)FOR_Z(1)FOR_Z(2)
				if( NUM(0)+((mod==2)?(-1):(1))*NUM(1)==NUM(2) )
							printf("%d %c %d = %d \n", NUM(0), (mod==2)?('-'):('+'), NUM(1), NUM(2));
		}
        
    }
    else if( opemod==0 ) // 一数字-
    {
        
	    // 两ope2 一ope1
		for(t=0; t<3; t++)
		{
		    // ？
		    // ？两ope2 一ope3 即 一ope3 其他ope2
			ope[0]=2; ope[1]=2; ope[2]=2;
			ope[t]=0; // ope0
			
			FOR_Z(0)FOR_Z(1)FOR_Z(2)
				if( NUM(0)+((mod==2)?(-1):(1))*NUM(1)==NUM(2) )
							printf("%d %c %d = %d \n", NUM(0), (mod==2)?('-'):('+'), NUM(1), NUM(2));
		}
        
    }
    else if( opemod==1 ) // 一数字+
    {
        
	    // 两ope2 一ope0
		for(t=0; t<3; t++)
		{
		    // ？
		    // ？两ope2 一ope3 即 一ope3 其他ope2
			ope[0]=2; ope[1]=2; ope[2]=2;
			ope[t]=1; // ope1
			
			FOR_Z(0)FOR_Z(1)FOR_Z(2)
				if( NUM(0)+((mod==2)?(-1):(1))*NUM(1)==NUM(2) )
							printf("%d %c %d = %d \n", NUM(0), (mod==2)?('-'):('+'), NUM(1), NUM(2));
		}
        
    }
    else if( opemod==2 ) // 数字不操作
    {
        
    	// 三ope2 
		ope[0]=2; ope[1]=2; ope[2]=2;
			
		FOR_Z(0)FOR_Z(1)FOR_Z(2)
			if( NUM(0)+((mod==2)?(-1):(1))*NUM(1)==NUM(2) )
						printf("%d %c %d = %d \n", NUM(0), (mod==2)?('-'):('+'), NUM(1), NUM(2));
		
    }
    
    
    // 待 合并 
}


 
// 十以内的两个数的加减
int f(int a, int mod, int b, int c)
{
	printf("Question : %d %c %d = %d\n", a, (mod==1)?('+'):('-'), b, c);
	printf("Answer   : ");
	
	/*
	if( mod==1 ) // '+'
	{
		//_f1_1(a, b, c); // 数-+ 
		//_f2_1(a, b, c); // 数+ '+'- 
		
		_f(a, mod, b, c, 4); // 两个数-+
		_f(a, mod, b, c, 3); // 一个数-+
		_f(a, 3-mod, b, c, 1); // 数+ '-'
	}
	else if( mod==2 ) // '-'
	{
		//_f1_2(a, b, c); // 数-+ 
		//_f2_2(a, b, c); // 数- '-'+ 
		
		_f(a, mod, b, c, 4); // 两个数-+
		_f(a, mod, b, c, 3); // 一个数-+
		_f(a, 3-mod, b, c, 0); // 数- '+'
	}
	else { return 0; }
	// 待合并
	*/
	
	_f(a, mod, b, c, 4); // 两个数-+
	_f(a, mod, b, c, 3); // 一个数-+
	_f(a, 3-mod, b, c, 2-mod); // 数- '+' / 数+ '-'
	
	
	return 1; // ？待 记录答案个数 返回答案个数 
}


int solve(const char *str)
{
	// 暂 只考虑 十以内的两个数的加减
	if( '0'<=str[0] && str[0]<='9' )
	if( str[1]=='+' || str[1]=='-' )
	if( '0'<=str[2] && str[2]<='9' )
	if( str[3]=='=' )
	if( '0'<=str[4] && str[4]<='9' )
	if( str[5]=='\0' )
		return f(str[0]-'0', (str[1]=='+')?(1):(2), str[2]-'0', str[4]-'0');
	return -1;
}

int main()
{
	//_ScanZM();
	// test Print
	/*
	int n;
	for(n=0; n<=9; n++)
		Print(n);
	*/
	
	
	f(6, 1, 8, 8); // 6+8=8 -> 8+0=8
	
	f(6, 1, 0, 8); // 6+0=8 -> 8-0=8
	
	f(8, 2, 9, 9); // 8-9=9 -> 0+9=9
	
	f(5, 1, 3, 6); // 5+3=6 -> 9-3=6
	
	
	
	/*
	solve("6+8=8"); // 6+8=8 -> 8+0=8
	solve("6+0=8"); // 6+0=8 -> 8-0=8
	solve("8-9=9"); // 8-9=9 -> 0+9=9
	solve("5+3=6"); // 5+3=6 -> 9-3=6
	*/ 
	
	
	f(9, 2, 9, 5);
	solve("9-9=5"); // 9-9=5 -> 9-3=6
	
	
	
	/*
	int n;
	char str[101];
	for(n=0; n<5; n++)
	{
		scanf("%s", str);
		solve(str);
	}
	*/
	
	
	/*
	int a, b, c;
	for(a=0; a<=9; a++)
		for(b=0; b<=9; b++)
			for(c=0; c<=9; c++)
			{
				f(a, 1, b, c);
				f(a, 2, b, c);
			}
	*/
	
	
	 
	return 0;
}


// 待 应对 其他改变符号
 
// 待 应对 移动多根火柴

// 待 应对 多位数  

// 待 应对 等号两边均为式子 


// 待 再优化 

