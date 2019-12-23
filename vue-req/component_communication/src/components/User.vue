<template>
  <div class="container">
    <h1>Parent Component (User)</h1>
    <p>Burası parent component yani herşeyin import edildiği component :)</p>
    <button @click="changeName">Adımı değiştir</button><hr>
    <p>Child component üzerinden gelen veri: {{ childData }} </p>
    <div class="row">
      <app-user-detail
        @data="childData = $event"
        @dataForSibling="reverseName = $event" 
        :name="title"
      ></app-user-detail>
      <app-user-edit 
        :rName="reverseName"
      ></app-user-edit>
    </div>
  </div>
</template>

<script>
  import UserDetail from "./UserDetail"
  import UserEdit from "./UserEdit"

  export default {
    components : {
      appUserDetail : UserDetail,
      appUserEdit : UserEdit,
    },
    data() {
      return {
        title: "vue",
        childData: "",
        reverseName: "",
      }
    },
    methods: {
      changeName() {
        this.title = "Defne"
      }
    }
  }
</script>

<style>
  div.container{
    margin-top: 30px;
    padding: 20px 40px;
    background-color: #6a8d99;
    border: 1px solid #666;
  }
  div.row {
    display: flex;
    align-items: center;
    justify-content: space-between;
  }
</style>
