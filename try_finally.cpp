int a = 0; // 0: default / 1: something doing / 2: something doing more / ...
int b = 0; // 0: default / 1: something doing / 2: something doing more / ...
int c = 0; // 0: default / 1: something doing / 2: something doing more / ...

void foo()
{
    try
    {
        a = 1;
        b = 2;
    }
    finally
    {
        a = 0;
        b = 0;
    }
}

void foo1()
{
    try
    {
        a = 3;
        c = 5;
    }
    finally
    {
        a = 0;
        c = 0; // this time, we rollback not b but c intentionally.
    }
}

void foo2()
{
    assert(a == 1);	// by contract 
    try
    {
        a = 3;	
        c = 4;
    }
    finally
    {
        a = 1;		// notice that a must be rolled back to 1, not 0! 
        c = 0;
    }
}
