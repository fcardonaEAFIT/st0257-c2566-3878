package co.edu.eafit.st0257;

public class JardinBloque implements Jardin {
    private int contador;

    public JardinBloque() {
	this.contador = 0;
    }

    public void entrar() {
	synchronized(this) {
	    contador++;
	}
    }

    public void salir() {
	synchronized(this) {
	    contador--;
	}
    }

    public int consultar() {
	int ret = 0;
	synchronized(this) {
	    ret = contador;
	}
	
	return ret;
    }
}
