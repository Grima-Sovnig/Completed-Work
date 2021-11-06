lapublic class Greeter {

    private String name;

    public String getName() {
        return name;
    }

    /**
     *
     * @param name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     *
     * @param name
     */
    public Greeter(String name) {
        this.name = name;
    }
}