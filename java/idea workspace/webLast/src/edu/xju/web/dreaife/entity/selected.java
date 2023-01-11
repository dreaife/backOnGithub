package edu.xju.web.dreaife.entity;

import java.sql.Timestamp;

public class selected {
    private int id;
    private int sid;
    private int cid;
    private Timestamp seTime;

    @Override
    public String toString() {
        return "selected{" +
                "id=" + id +
                ", sid=" + sid +
                ", cid=" + cid +
                ", seTime=" + seTime +
                '}';
    }

    public selected() {
    }

    public selected(int id, int sid, int cid, Timestamp seTime) {
        this.id = id;
        this.sid = sid;
        this.cid = cid;
        this.seTime = seTime;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getSid() {
        return sid;
    }

    public void setSid(int sid) {
        this.sid = sid;
    }

    public int getCid() {
        return cid;
    }

    public void setCid(int cid) {
        this.cid = cid;
    }

    public Timestamp getSeTime() {
        return seTime;
    }

    public void setSeTime(Timestamp seTime) {
        this.seTime = seTime;
    }
}
