
/* �ƶ������Ϸ */ 

// ���� �Ż�




// ��Ϸ��·��
// 1.���ı����ֻ�ı����� 
// 2.�ı���ź����� 
// 3.���ı�����ֻ�ı���� 
// 4.���������� 
// ps: �Ⱥſ� -�ɸ��� -+�ɼӺ�


#include <stdio.h>



int _PRIZM[10]={  // �����ƴ� 15λ0/1 
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

// ��ӡ 
void Print(int num)
{
	if( num<0 || num>9 )return ;
	
	int k, n=_PRIZM[num], cnt=0;
	for(k=1<<(15-1); k>0; k>>=1)
		printf("%s%c", (k&n)?("��"):("  "), ((++cnt)%3==0)?('\n'):(' '));
	printf("\n"); 
}

//void PrintStr(


// ¼��ģ 
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

// �� ������ʹ�� Print 



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
// ʮ���ڵ��������ļ� _ �����ּ��� ('+')
void _f1_1(int a, int b, int c) 
{
	int n[3]={a, b, c}; // a b c 
	int ope[3]; // opea opeb opec
	int z[3]; // za zb zc
	
	// ��������-+ 
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
	
	// ��һ����-+ 
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

// ʮ���ڵ��������ļ� _ �����ּ��� ('-')
void _f1_2(int a, int b, int c) 
{
	int n[3]={a, b, c}; // a b c 
	int ope[3]; // opea opeb opec
	int z[3]; // za zb zc
	
	// ��������-+ 
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
	
	// ��һ����-+ 
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


// ʮ���ڵ��������ļ� _ �������� '+'����'-' 
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

// ʮ���ڵ��������ļ� _ �����ּ� '-'�ӳ�'+' 
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

// �� ���ݺϲ�

// �� �Ż������� ������ �� 
*/


void _f(int a, int mod, int b, int c, int opemod) // a mod b = c �����޸ķ�ʽopemod (mod�Ǹĺ�򲻸ĵķ���)
{
	int n[3]={a, b, c}; // a b c
	int ope[3]; // opea opeb opec
	int z[3]; // za zb zc
	int t;
	
    if( opemod<0 || opemod>4 )
    { return -1; }
    else if( opemod==4 ) // ������-+
    {
    
	    // һope0 һope1 һope2
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
					    // ��
					    // ���� if Ϊ ��Ŀ����
					    // ��...
						if( NUM(0)+((mod==2)?(-1):(1))*NUM(1)==NUM(2) )
							printf("%d %c %d = %d \n", NUM(0), (mod==2)?('-'):('+'), NUM(1), NUM(2));
				}
			}
		}
        
    }
    else if( opemod==3 ) // һ����-+
    {
        
	    // ��ope2 һope3
		for(t=0; t<3; t++)
		{
		    // ��
		    // ����ope2 һope3 �� һope3 ����ope2
			ope[0]=2; ope[1]=2; ope[2]=2;
			ope[t]=3; // ope3
			
			FOR_Z(0)FOR_Z(1)FOR_Z(2)
				if( NUM(0)+((mod==2)?(-1):(1))*NUM(1)==NUM(2) )
							printf("%d %c %d = %d \n", NUM(0), (mod==2)?('-'):('+'), NUM(1), NUM(2));
		}
        
    }
    else if( opemod==0 ) // һ����-
    {
        
	    // ��ope2 һope1
		for(t=0; t<3; t++)
		{
		    // ��
		    // ����ope2 һope3 �� һope3 ����ope2
			ope[0]=2; ope[1]=2; ope[2]=2;
			ope[t]=0; // ope0
			
			FOR_Z(0)FOR_Z(1)FOR_Z(2)
				if( NUM(0)+((mod==2)?(-1):(1))*NUM(1)==NUM(2) )
							printf("%d %c %d = %d \n", NUM(0), (mod==2)?('-'):('+'), NUM(1), NUM(2));
		}
        
    }
    else if( opemod==1 ) // һ����+
    {
        
	    // ��ope2 һope0
		for(t=0; t<3; t++)
		{
		    // ��
		    // ����ope2 һope3 �� һope3 ����ope2
			ope[0]=2; ope[1]=2; ope[2]=2;
			ope[t]=1; // ope1
			
			FOR_Z(0)FOR_Z(1)FOR_Z(2)
				if( NUM(0)+((mod==2)?(-1):(1))*NUM(1)==NUM(2) )
							printf("%d %c %d = %d \n", NUM(0), (mod==2)?('-'):('+'), NUM(1), NUM(2));
		}
        
    }
    else if( opemod==2 ) // ���ֲ�����
    {
        
    	// ��ope2 
		ope[0]=2; ope[1]=2; ope[2]=2;
			
		FOR_Z(0)FOR_Z(1)FOR_Z(2)
			if( NUM(0)+((mod==2)?(-1):(1))*NUM(1)==NUM(2) )
						printf("%d %c %d = %d \n", NUM(0), (mod==2)?('-'):('+'), NUM(1), NUM(2));
		
    }
    
    
    // �� �ϲ� 
}


 
// ʮ���ڵ��������ļӼ�
int f(int a, int mod, int b, int c)
{
	printf("Question : %d %c %d = %d\n", a, (mod==1)?('+'):('-'), b, c);
	printf("Answer   : ");
	
	/*
	if( mod==1 ) // '+'
	{
		//_f1_1(a, b, c); // ��-+ 
		//_f2_1(a, b, c); // ��+ '+'- 
		
		_f(a, mod, b, c, 4); // ������-+
		_f(a, mod, b, c, 3); // һ����-+
		_f(a, 3-mod, b, c, 1); // ��+ '-'
	}
	else if( mod==2 ) // '-'
	{
		//_f1_2(a, b, c); // ��-+ 
		//_f2_2(a, b, c); // ��- '-'+ 
		
		_f(a, mod, b, c, 4); // ������-+
		_f(a, mod, b, c, 3); // һ����-+
		_f(a, 3-mod, b, c, 0); // ��- '+'
	}
	else { return 0; }
	// ���ϲ�
	*/
	
	_f(a, mod, b, c, 4); // ������-+
	_f(a, mod, b, c, 3); // һ����-+
	_f(a, 3-mod, b, c, 2-mod); // ��- '+' / ��+ '-'
	
	
	return 1; // ���� ��¼�𰸸��� ���ش𰸸��� 
}


int solve(const char *str)
{
	// �� ֻ���� ʮ���ڵ��������ļӼ�
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


// �� Ӧ�� �����ı����
 
// �� Ӧ�� �ƶ�������

// �� Ӧ�� ��λ��  

// �� Ӧ�� �Ⱥ����߾�Ϊʽ�� 


// �� ���Ż� 

