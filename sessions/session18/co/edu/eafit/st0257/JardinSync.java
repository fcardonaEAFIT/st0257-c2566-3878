package co.edu.eafit.st0257;

public class JardinSync implements Jardin {
    private int contador;

    public JardinSync() {
	this.contador = 0;
    }

    public synchronized void entrar() {
	contador++;
    }

    public synchronized void salir() {
	contador--;
    }

    public synchronized int consultar() {
	return contador;
    }
}
