int tailRecursiveFactorial(int num, int result=1)
{
 if(num<=0)
 	return result;
 
 return tailRecursiveFactorial(num-1,result*num);	
}	
