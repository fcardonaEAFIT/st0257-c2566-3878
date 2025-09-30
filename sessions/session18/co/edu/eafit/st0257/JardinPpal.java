package co.edu.eafit.st0257;

public class JardinPpal {

    public static void main(String args[]) {

	Jardin jardin = null;
	if (args.length == 0) {
	    jardin = new JardinSync();
	}
	else {
	    jardin = new JardinBloque();
	}
	
	Thread visitantes[] = new Thread[200];
	Thread administrador = new Thread(new Administrador(jardin));

	administrador.start();
	for (int i = 0; i < 200; i++) {
	    visitantes[i] = new Thread(new Visitante(jardin));
	    visitantes[i].start();
	}
    }
}

	
			  
				       
				  
