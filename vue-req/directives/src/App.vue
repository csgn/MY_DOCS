<template>
  <div class="container">
    <div class="row">
      <div class="col-md-6 col-md-offset-3">
        <p
          v-color.delay="'red'"
        >Lorem ipsum dolor sit amet consectetur adipisicing elit. Sunt repellendus autem accusantium alias deserunt! Expedita nisi adipisci pariatur? Quidem aspernatur ullam aut dicta eveniet nisi excepturi hic veniam debitis repellat.</p>
        <p
          v-color:background.delay.flash=" {mainColor: 'green', secondColor: 'blue', delay: 500} "
        >Lorem ipsum dolor, sit amet consectetur adipisicing elit. Debitis eaque accusamus, pariatur voluptatibus aliquid rem officia dolorem dolore ut dignissimos eligendi asperiores, vitae ipsam numquam laboriosam? Accusamus voluptatibus nam qui?</p>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  directives: {
    color: {
      bind(el, binding) {
        let delay = 0;

        if (binding.modifiers["delay"]) {
          delay = 2000;
        }

        if (binding.modifiers["flash"]) {
          let firstColor = binding.value.mainColor;
          let secondColor = binding.value.secondColor;
          let currentColor = firstColor;

          setTimeout(() => {
            setInterval(() => {
              currentColor == secondColor
                ? (currentColor = firstColor)
                : (currentColor = secondColor);
              if (binding.arg == "background") {
                el.style.backgroundColor = currentColor;
              } else {
                el.style.color = currentColor;
              }
            }, binding.value.delay);
          }, delay);
        } else {
          setTimeout(() => {
            if (binding.arg == "background") {
              el.style.backgroundColor = binding.value;
            } else {
              el.style.color = binding.value;
            }
          }, delay);
        }
      }
    }
  }
};
</script>

<style>
</style>
