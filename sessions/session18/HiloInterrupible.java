public class HiloInterrupible {

    public static void main(String[] args) {
	Thread t = new Thread(() -> {
		while(true) {
		    try {
			System.out.println("Estoy trabajando");
			Thread.sleep(1000);
		    }
		    catch (InterruptedException ie) {
			// Thread.currentThread().interrupted();
			break;
		    }
		}
	});
	t.start();
	// Hilo principal
	try {
	    Thread.sleep(5000);
	    t.interrupt();
	}
	catch (InterruptedException ie) {
	    
	}
    } 
}
