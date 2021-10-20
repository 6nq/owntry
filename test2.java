package test1;

public class test2 {

	public static void main(String[] args) {
        OemFactory creater = new HpCreater();
        Computer hp = creater.CreateProduct();
        hp.ProductMethod();

        creater = new AcerCreater();
        Computer acer = creater.CreateProduct();
        acer.ProductMethod();

        creater = new DellCreater();
        Computer dell = creater.CreateProduct();
        dell.ProductMethod();

        creater = new LenovoCreater();
        Computer lenovo = creater.CreateProduct();
        lenovo.ProductMethod();
	}

}

abstract class Computer {
    public abstract void ProductMethod();
} 
class Hp extends Computer {
    @Override
    public void ProductMethod() {
        System.out.println("Hp Computer");
    }
}

class Acer extends Computer {
    @Override
    public void ProductMethod() {
        System.out.println("Acer Computer");
    }
}
class Lenovo extends Computer {
    @Override
    public void ProductMethod() {
        System.out.println("Lenovo Computer");
    }
}
class Dell extends Computer {
    @Override
    public void ProductMethod() {
        System.out.println("Dell Computer");
    }
}

abstract class OemFactory {
    public abstract Computer CreateProduct();
}

class HpCreater extends OemFactory {
    @Override
    public Computer CreateProduct() {
        System.out.println("Hp Computer Create");
        return new Hp();
    }
}

class AcerCreater extends OemFactory {
    @Override
    public Computer CreateProduct() {
        System.out.println("Acer Computer Create");
        return new Acer();
    }
}
class LenovoCreater extends OemFactory {
    @Override
    public Computer CreateProduct() {
        System.out.println("Lenovo Computer Create");
        return new Lenovo();
    }
}
class DellCreater extends OemFactory {
    @Override
    public Computer CreateProduct() {
        System.out.println("Dell Computer Create");
        return new Dell();
    }
}
