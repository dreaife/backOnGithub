package ProjectTest.demo.entity;

import java.io.Serializable;
import java.sql.Time;
import java.sql.Timestamp;
import java.util.PrimitiveIterator;

public class User implements Serializable {

    private static final long serialVersionUID = 1L;

    private  Integer id;
    private  String userName;
    private  String password;
    private  String email;
    private  String phone;
    private  Timestamp created;
    private  Timestamp updated;

    public User(){}

    public User(String userName, String password, String email, String phone) {
        this.userName = userName;
        this.password = password;
        this.email = email;
        this.phone = phone;
    }

    public User(Integer id, String userName, String password, String email, String phone, Timestamp created, Timestamp updated) {
        this.id = id;
        this.userName = userName;
        this.password = password;
        this.email = email;
        this.phone = phone;
        this.created = created;
        this.updated = updated;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public Timestamp getCreated() {
        return created;
    }

    public void setCreated(Timestamp created) {
        this.created = created;
    }

    public Timestamp getUpdated() {
        return updated;
    }

    public void setUpdated(Timestamp updated) {
        this.updated = updated;
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        return super.equals(obj);
    }

    @Override
    public String toString() {
        return super.toString();
    }
}
