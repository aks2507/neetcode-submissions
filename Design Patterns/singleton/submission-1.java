static class Singleton {

    private static String value;
    private static Singleton unique = null;
    private Singleton() {}

    public static Singleton getInstance() {
        if (unique == null) {
            return new Singleton();
        }

        return unique;
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }
    
}
