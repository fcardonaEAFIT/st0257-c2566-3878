public class Hilo4  {

    public static void main(String...args) {
	Runnable r = () -> {
	    for (int i = 0; i < 10; i++) {
		System.out.println("Hilo 4");
	    }};
	Thread t = new Thread(r);
	t.start();
	System.out.println("" +t.isAlive());
	try {
	    t.stop();
	    t.join();
	}
	catch (InterruptedException ie) { }
	    
	System.out.println("" + t.isAlive());
	t.start();
    }
}
