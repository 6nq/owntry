package test1;

public class test1 {

	public static void main(String[] args) {
        AppConfig instance1 = AppConfig.getInstance();
        System.out.println(
            instance1.SetParaneter("Hello ")
                     .GetParaneter());
        AppConfig instance2 = AppConfig.getInstance();
        System.out.println(
            instance2.SetParaneter("World!")
                     .GetParaneter());
	}
}

class AppConfig {
    private static volatile AppConfig instance;    //保证 instance 在所有线程中同步
    private String paraneter;
    
    private AppConfig() {
        paraneter = null;
    }    //private 避免类在外部被实例化

    public String GetParaneter(){
        return paraneter;
    }

    public AppConfig SetParaneter(String newParaneter){
        paraneter = newParaneter;
        return this;
    }

    public static AppConfig getInstance() {
        if (instance == null) {
            synchronized (AppConfig.class) {
                if (instance == null) {
                    instance = new AppConfig();
                }
            }
        }
        return instance;
    }
}
