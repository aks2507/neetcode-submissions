static class Singleton {

    private static String value;
    private Singleton() {

    }

    public static Singleton getInstance() {
        return new Singleton();
    }

    public String getValue() {
        return this.value;
    }

    public void setValue(String value) {
        this.value = value;
    }
    
}
