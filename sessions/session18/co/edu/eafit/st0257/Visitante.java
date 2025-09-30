package co.edu.eafit.st0257;

import java.util.Random;
import static java.lang.Math.abs;

public class Visitante implements Runnable {
    private Jardin jardin;
    private Random random;

    public Visitante(Jardin jardin) {
	this.jardin = jardin;
	this.random = new Random(System.currentTimeMillis());
    }

    public void run() {
	while (true) {
	    try {
		Thread.sleep(abs(random.nextInt()) % 5000 + 1000);
		jardin.entrar();
		Thread.sleep(abs(random.nextInt()) % 8000 + 1000);
		jardin.salir();
	    }
	    catch (InterruptedException ie) {
	    }
	}   		
    }
}
