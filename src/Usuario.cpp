
    Usuario::Usuario() {
        
    }

    Usuario(std::string ci, std::string nombre, std::string password);
    Usuario(Usuario &c);
    std::string getCi() const;
    std::string getNombre() const;
    std::string getPassword() const;
    // DTFecha getFecha() const; esto será sólo de LECTOR
    // int getCantidadPrestamos() const;
    // Prestamo** getPrestamos();
    // void addPrestamo(Prestamo* prestamo);
    bool checkPassword(std::string password) const;
    virtual ~Usuario();
};
#endif