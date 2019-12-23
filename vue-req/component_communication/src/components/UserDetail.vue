<template>
  <div class="wcol-md-6">
    <h3>Child Component 1</h3>
    <p>Ben User.vue isimli Parent Component'in içerisindeki bir Child componentim</p>
    <p> Kullanici Adi: {{ name }} </p>
    <p> Ters: {{ reverseName() }} </p>
    <button @click="sendToParent()">Veriyi Parent'a Gönder</button>
    <button @click="sendToParentForSibling()">Veriyi Sibling İçin Parent a Gönder</button>
    <p>eventBus ile sibling den gelen veri: {{ withBusName }} </p>
  </div>
</template>

<script>
  import { eventBus } from "../main"

  export default {
    //props: ['name'],
    props: { // props validation
      //name: [String, Array] // String veya Array gelebilir
      name: {
        type: String, // String tipi gelecektir
        required: true, // zorunludur
        default: "varsayilan-deger" // Herhangi bir deger gelmez ise varsayilan olarak atanan deger
      }
    },
    data() {
      return {
        rName: "",
        withBusName: "",
      }
    },
    methods: {
      reverseName() {
        this.rName = this.name.split("").reverse().join("")
        return this.rName
      },
      sendToParent() {
        this.$emit("data", "Defne") // emit = yaymak demektir
      },
      sendToParentForSibling() {
        this.$emit("dataForSibling", this.rName)
      }
    },
    created() {
      eventBus.$on("withBus", (withBusData) => { // $on fonksiyonu ile dinlemeye alınır
        this.withBusName = withBusData
      })
    }
  }
</script>

<style scoped>
  div {
    background-color: lightcoral;
    padding: 20px;
    border: 1px solid #666;
    display: inline-block;
  }
</style>
