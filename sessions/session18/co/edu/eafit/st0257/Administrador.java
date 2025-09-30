package co.edu.eafit.st0257;

import java.util.Random;
import static java.lang.Math.abs;

public class Administrador  implements Runnable {
    private Jardin jardin;
    private Random random;

    public Administrador(Jardin jardin) {
	this.jardin = jardin;
	this.random = new Random(System.currentTimeMillis());
    }

    public void run() {
	while (true) {
	    try {
		Thread.sleep(abs(random.nextInt()) % 10000 + 1000);
		System.out.printf("Visitantes: %d%n", jardin.consultar());
	    }
	    catch (InterruptedException ie) {
	    }
	}   		
    }
}
