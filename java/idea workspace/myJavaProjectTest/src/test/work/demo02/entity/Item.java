package test.work.demo02.entity;

import java.io.Serializable;

public class Item implements Serializable{
	private static final long serialVersionUID = 1L;
	private Integer id;
	private String title;
	private Double price;
	private Integer num;
	private String itype;
	private String color;
	public Item(){}
	public Item(Integer id, String title, Double price, Integer num, String itype, String color) {
		super();
		this.id = id;
		this.title = title;
		this.price = price;
		this.num = num;
		this.itype = itype;
		this.color = color;
	}
	public Integer getId() {
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public Double getPrice() {
		return price;
	}
	public void setPrice(Double price) {
		this.price = price;
	}
	public Integer getNum() {
		return num;
	}
	public void setNum(Integer num) {
		this.num = num;
	}
	public String getItype() {
		return itype;
	}
	public void setItype(String itype) {
		this.itype = itype;
	}
	public String getColor() {
		return color;
	}
	public void setColor(String color) {
		this.color = color;
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((id == null) ? 0 : id.hashCode());
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Item other = (Item) obj;
		if (id == null) {
			if (other.id != null)
				return false;
		} else if (!id.equals(other.id))
			return false;
		return true;
	}
	@Override
	public String toString() {
		return "Item [id=" + id + ", title=" + title + ", price=" + price + ", num=" + num + ", itype=" + itype
				+ ", color=" + color + "]";
	}
	
	
	
	

}
