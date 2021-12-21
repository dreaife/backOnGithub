package test.work.demo02.entity;

import java.io.Serializable;
import java.sql.Timestamp;

public class ItemCart implements Serializable{
	private static final long serialVersionUID = 1L;
	private Integer id;
	private Integer userId;
	private Integer itemId;
	private Double price;
	private Integer num;
	private Timestamp created;
	private Timestamp updated;
	public ItemCart(){}
	public ItemCart(Integer id, Integer userId, Integer itemId, Double price, Integer num, Timestamp created,
			Timestamp updated) {
		super();
		this.id = id;
		this.userId = userId;
		this.itemId = itemId;
		this.price = price;
		this.num = num;
		this.created = created;
		this.updated = updated;
	}
	public Integer getId() {
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public Integer getUserId() {
		return userId;
	}
	public void setUserId(Integer userId) {
		this.userId = userId;
	}
	public Integer getItemId() {
		return itemId;
	}
	public void setItemId(Integer itemId) {
		this.itemId = itemId;
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
		ItemCart other = (ItemCart) obj;
		if (id == null) {
			if (other.id != null)
				return false;
		} else if (!id.equals(other.id))
			return false;
		return true;
	}
	@Override
	public String toString() {
		return "ItemCart [id=" + id + ", userId=" + userId + ", itemId=" + itemId + ", price=" + price + ", num=" + num
				+ ", created=" + created + ", updated=" + updated + "]";
	}
	
	

}
