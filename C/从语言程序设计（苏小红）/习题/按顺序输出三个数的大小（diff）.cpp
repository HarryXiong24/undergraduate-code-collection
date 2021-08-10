/*按顺序输出三个数的大小（方法很巧妙，想办法确定一个最小数）*/
#include<stdio.h>
main()
{
	int x,y,z,t;
	printf("Input x,y,z:");
	scanf("%d%*c%d%*c%d",&x,&y,&z);
	if(x>y)
    {
    	t=x;
    	x=y;
    	y=t;
    	/*通过这三步则让更小值转化在x上*/
	}
	if(x>z)
	{
		t=x;
		x=z;
		z=t;
		/*通过这三步则让更小值转化在x上*/
	} 
	if(y>z)
	{
		t=y;
		y=z;
		z=t;	
		/*通过这三步则让更小值转化在y上*/
		
	}
	printf("small to big:%d,%d,%d",x,y,z);
	printf("\n最大数为：%d",z) ;
 } 
 
