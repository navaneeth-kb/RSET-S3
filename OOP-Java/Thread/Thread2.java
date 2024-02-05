class EvenThread extends Thread
{
    EvenThread()
    {
        start();
    }
    public void run()
    {
        try
        {
            for(int i=0;i<11;i+=2)
            {
                System.out.println(i);
                Thread.sleep(500);
            }
        }
        catch(InterruptedException e)
        {
            System.out.println("eventhread interrupted");
        }
    }
}
class OddThread extends Thread
{
    OddThread()
    {
        start();
    }
    public void run()
    {
        try
        {
            for(int i=1;i<11;i+=2)
            {
                System.out.println(i);
                Thread.sleep(500);
            }
        }
        catch(InterruptedException e)
        {
            System.out.println("oddthread interrupted");
        }
    }
}
class Thread2
{
    public static void main(String[] args) {
        EvenThread et=new EvenThread();
        OddThread ot=new OddThread();
    }
}