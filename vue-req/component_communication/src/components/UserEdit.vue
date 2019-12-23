<template>
  <div class="col-md-s6">
    <h3>Child Component 2</h3>
    <p>Ben User.vue isimli Parent Component'in içerisindeki bir diğer Child componentim</p>
    <p>Ters Kullanıcı Adı: {{ rName }} </p>
    <button @click="withBus"> Veriyi eventBus ile sibling e gönder </button>
  </div>
</template>

<script>
  import { eventBus } from "../main"

  export default {
    props: ["rName"],
    data() {
      return {
        withBusName: "",
      }
    },
    methods: {
      withBus() {
        this.withBusName = this.rName.split("").reverse().join("")
        eventBus.$emit("withBus", this.withBusName)
      },
    }
  }
</script>

<style scoped>
  div {
    background-color: lightgoldenrodyellow;
    padding: 20px;
    border: 1px solid #666;
    display: inline-block;
  }
</style>

