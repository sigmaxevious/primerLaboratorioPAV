
class DTFecha{
    private:
        int dia;
        int mes;
        int año;
    public:
        DTFecha();
        DTFecha(int dia, int mes, int año);
        DTFecha(DTFecha &c);
        int getDia();
        int getMes();
        int getAño();
        ~DTFecha();
}