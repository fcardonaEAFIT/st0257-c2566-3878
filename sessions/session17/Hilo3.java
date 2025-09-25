public class Hilo3  {

    public static void main(String...args) {
	Runnable r = () -> {
	    for (int i = 0; i < 10; i++) {
		System.out.println("Hilo3");
	    }};
	Thread t = new Thread(r);
	t.start();
    }
}
