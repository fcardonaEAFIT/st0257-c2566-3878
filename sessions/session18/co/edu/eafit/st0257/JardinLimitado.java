package co.edu.eafit.st0257;

public class JardinLimitado implements Jardin {
    private int contador;
    private int limite;

    public JardinSync(int limite) {
	this.contador = 0;
	this.limite = limite;
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
